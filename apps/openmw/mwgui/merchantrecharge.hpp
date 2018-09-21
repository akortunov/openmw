#ifndef OPENMW_MWGUI_MERCHANTRECHARGE_H
#define OPENMW_MWGUI_MERCHANTRECHARGE_H

#include "windowbase.hpp"
#include "../mwworld/ptr.hpp"

namespace MWGui
{

class MerchantRecharge : public WindowBase
{
public:
    MerchantRecharge();

    virtual void onOpen();

    void setPtr(const MWWorld::Ptr& actor);

private:
    MyGUI::ScrollView* mList;
    MyGUI::Button* mOkButton;
    MyGUI::TextBox* mGoldLabel;

    MWWorld::Ptr mActor;

protected:
    void onMouseWheel(MyGUI::Widget* _sender, int _rel);
    void onRechargeButtonClick(MyGUI::Widget* sender);
    void onOkButtonClick(MyGUI::Widget* sender);

    static const int sLineHeight;
};

}

#endif
