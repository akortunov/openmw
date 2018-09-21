#include "merchantrecharge.hpp"

#include <components/esm/loadgmst.hpp>

#include <MyGUI_Button.h>
#include <MyGUI_ScrollView.h>
#include <MyGUI_Gui.h>

#include "../mwbase/world.hpp"
#include "../mwbase/environment.hpp"
#include "../mwbase/mechanicsmanager.hpp"
#include "../mwbase/windowmanager.hpp"

#include "../mwmechanics/creaturestats.hpp"
#include "../mwmechanics/actorutil.hpp"

#include "../mwworld/class.hpp"
#include "../mwworld/containerstore.hpp"
#include "../mwworld/esmstore.hpp"

namespace MWGui
{
MerchantRecharge::MerchantRecharge()
    : WindowBase("openmw_merchantrecharge.layout")
{
    getWidget(mList, "RechargeView");
    getWidget(mOkButton, "OkButton");
    getWidget(mGoldLabel, "PlayerGold");

    mOkButton->eventMouseButtonClick += MyGUI::newDelegate(this, &MerchantRecharge::onOkButtonClick);
}

void MerchantRecharge::setPtr(const MWWorld::Ptr &actor)
{
    mActor = actor;

    while (mList->getChildCount())
        MyGUI::Gui::getInstance().destroyWidget(mList->getChildAt(0));

    int lineHeight = MWBase::Environment::get().getWindowManager()->getFontHeight() + 2;
    int currentY = 0;

    MWWorld::Ptr player = MWMechanics::getPlayer();
    int playerGold = player.getClass().getContainerStore(player).count(MWWorld::ContainerStore::sGoldId);

    MWWorld::ContainerStore& store = player.getClass().getContainerStore(player);
    for (MWWorld::ContainerStoreIterator iter (store.begin()); iter!=store.end(); ++iter)
    {
        std::string enchId = iter->getClass().getEnchantment(*iter);
        if (!enchId.empty())
        {
            const ESM::Enchantment* enchantment = MWBase::Environment::get().getWorld()->getStore().get<ESM::Enchantment>().find(enchId);
            int maxCharges = enchantment->mData.mCharge;
            int charges = iter->getCellRef().getEnchantmentCharge();
            if (maxCharges <= charges || charges == -1)
                continue;

            int basePrice = iter->getClass().getValue(*iter);
            const float fEnchantmentValueMult = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>()
                    .find("fEnchantmentValueMult")->mValue.getFloat();

            float p = static_cast<float>(std::max(1, basePrice));
            float r = static_cast<float>(std::max(1, static_cast<int>(maxCharges / p)));

            int x = static_cast<int>((maxCharges - charges) / r);
            x = static_cast<int>(fEnchantmentValueMult * x / 100);

            int price = MWBase::Environment::get().getMechanicsManager()->getBarterOffer(mActor, x, true);

            std::string name = iter->getClass().getName(*iter)
                    + " - " + MyGUI::utility::toString(price)
                    + MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>()
                    .find("sgp")->mValue.getString();

            MyGUI::Button* button =
                mList->createWidget<MyGUI::Button>(price <= playerGold ? "SandTextButton" : "SandTextButtonDisabled", // can't use setEnabled since that removes tooltip
                    0,
                    currentY,
                    0,
                    lineHeight,
                    MyGUI::Align::Default
                );

            currentY += lineHeight;

            button->setUserString("Price", MyGUI::utility::toString(price));
            button->setUserData(MWWorld::Ptr(*iter));
            button->setCaptionWithReplacing(name);
            button->setSize(mList->getWidth(),lineHeight);
            button->eventMouseWheel += MyGUI::newDelegate(this, &MerchantRecharge::onMouseWheel);
            button->setUserString("ToolTipType", "ItemPtr");
            button->eventMouseButtonClick += MyGUI::newDelegate(this, &MerchantRecharge::onRechargeButtonClick);
        }
    }
    // Canvas size must be expressed with VScroll disabled, otherwise MyGUI would expand the scroll area when the scrollbar is hidden
    mList->setVisibleVScroll(false);
    mList->setCanvasSize (MyGUI::IntSize(mList->getWidth(), std::max(mList->getHeight(), currentY)));
    mList->setVisibleVScroll(true);

    mGoldLabel->setCaptionWithReplacing("#{sGold}: "
        + MyGUI::utility::toString(playerGold));
}

void MerchantRecharge::onMouseWheel(MyGUI::Widget* _sender, int _rel)
{
    if (mList->getViewOffset().top + _rel*0.3f > 0)
        mList->setViewOffset(MyGUI::IntPoint(0, 0));
    else
        mList->setViewOffset(MyGUI::IntPoint(0, static_cast<int>(mList->getViewOffset().top + _rel*0.3f)));
}

void MerchantRecharge::onOpen()
{
    center();
    // Reset scrollbars
    mList->setViewOffset(MyGUI::IntPoint(0, 0));
}

void MerchantRecharge::onRechargeButtonClick(MyGUI::Widget *sender)
{
    MWWorld::Ptr player = MWMechanics::getPlayer();

    int price = MyGUI::utility::parseInt(sender->getUserString("Price"));
    if (price > player.getClass().getContainerStore(player).count(MWWorld::ContainerStore::sGoldId))
        return;

    // recharge
    MWWorld::Ptr item = *sender->getUserData<MWWorld::Ptr>();

    const ESM::Enchantment* enchantment = MWBase::Environment::get().getWorld()->getStore().get<ESM::Enchantment>().find(
                    item.getClass().getEnchantment(item));
    item.getCellRef().setEnchantmentCharge(static_cast<float>(enchantment->mData.mCharge));

    player.getClass().getContainerStore(player).restack(item);

    MWBase::Environment::get().getWindowManager()->playSound("Enchant Success");

    player.getClass().getContainerStore(player).remove(MWWorld::ContainerStore::sGoldId, price, player);

    // add gold to NPC trading gold pool
    MWMechanics::CreatureStats& actorStats = mActor.getClass().getCreatureStats(mActor);
    actorStats.setGoldPool(actorStats.getGoldPool() + price);

    setPtr(mActor);
}

void MerchantRecharge::onOkButtonClick(MyGUI::Widget *sender)
{
    MWBase::Environment::get().getWindowManager()->removeGuiMode(GM_MerchantRecharge);
}

}
