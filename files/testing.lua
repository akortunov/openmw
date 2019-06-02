--SomethingScript in morrowind.omwgame has a short named hello you can use

local testing = {}

function testing.run()
    print("health: "..omw.gethealth("player"))
    print("hello i'm a criminal")
    omw.setpccrimelevel(100000000)
    print("flying: "..omw.getflying("player"))
    omw.setflying("player",1)
    print("flying: "..omw.getflying("player"))
    print("random100: "..omw.omwget("random100"))
    omw.omwset("random100",42)
    print("random100: "..omw.omwget("random100"))
--    print("SomethingScript.hello: "..omw.omwget("SomethingScript.hello"))
--    omw.omwset("SomethingScript.hello",42.0)
--    print("SomethingScript.hello: "..omw.omwget("SomethingScript.hello"))
    omw.omwcall("MessageBox, \"This is a simple message\"")
end

return testing
