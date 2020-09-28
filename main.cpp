#include <iostream>
#include "Poco/JSON/Parser.h"
std::string getStaData(std::string str)
{
    if(!str.empty())
    {
        return "["+ str.substr(0, str.length() - 1) + "]";
    }
    return "";
}
int main() {
    std::string jsonString = R"(
{
  "data" : [
    {
      "dnsConfiguration" : [
        {
          "id" : "76482b87-bba8-5017-a79e-cec5b314031f",
          "name" : "APN1",
          "uri" : "\/onlinestate\/dnsConfigurations\/76482b87-bba8-5017-a79e-cec5b314031f"
        },
        {
          "id" : "8cb496a4-505c-55c2-8fca-78a7868cafeb",
          "name" : "APN2",
          "uri" : "\/onlinestate\/dnsConfigurations\/8cb496a4-505c-55c2-8fca-78a7868cafeb"
        }
      ],
      "id" : "3ce6c960-ccf1-5db0-8a30-0c806b7e98a2",
      "modemOperationState" : "normalOperation",
      "name" : "modemDevice",
      "networkConnectionState" : "connected",
      "networkProvider" : {
        "id" : "a7910056-8a65-5e6f-b2e8-650aead26ea8",
        "name" : "networkProvider",
        "uri" : "\/onlinestate\/networkProviders\/a7910056-8a65-5e6f-b2e8-650aead26ea8"
      },
      "networkRegistrationState" : "registed",
      "networkTechnology" : "LTE",
      "networkTechnologyGeneration" : "",
      "signalQuality" : 38,
      "uri" : "\/onlinestate\/modemDevices\/3ce6c960-ccf1-5db0-8a30-0c806b7e98a2"
    },{
      "dnsConfiguration" : [
        {
          "id" : "76482b87-bba8-5017-a79e-cec5b314031f",
          "name" : "APN1",
          "uri" : "\/onlinestate\/dnsConfigurations\/76482b87-bba8-5017-a79e-cec5b314031f"
        },
        {
          "id" : "8cb496a4-505c-55c2-8fca-78a7868cafeb",
          "name" : "APN2",
          "uri" : "\/onlinestate\/dnsConfigurations\/8cb496a4-505c-55c2-8fca-78a7868cafeb"
        }
      ],
      "id" : "3ce6c960-ccf1-5db0-8a30-0c806b7e98a2",
      "modemOperationState" : "normalOperation",
      "name" : "modemDevice",
      "networkConnectionState" : "connected",
      "networkProvider" : {
        "id" : "a7910056-8a65-5e6f-b2e8-650aead26ea8",
        "name" : "networkProvider",
        "uri" : "\/onlinestate\/networkProviders\/a7910056-8a65-5e6f-b2e8-650aead26ea8"
      },
      "networkRegistrationState" : "registed",
      "networkTechnology" : "LTE",
      "networkTechnologyGeneration" : "gen3",
      "signalQuality" : 38,
      "uri" : "\/onlinestate\/modemDevices\/3ce6c960-ccf1-5db0-8a30-0c806b7e98a2"
    }
  ],
  "status" : "ok"
})";
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result;
    parser.reset();
//    auto t = parser.asVar();
//    if (t.isEmpty()) {
//        std::cout << "11t ==empty" << std::endl;
//    }
    result = parser.parse(jsonString);
    if (result.isEmpty()) {
        std::cout << "result ==empty" << std::endl;
    }
    std::string netstr;
    std::string netconstatestr;
    std::string netregstatestr;
    std::string sigqualitystr;

    Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
    Poco::JSON::Array::Ptr array = object->getArray("data");
    Poco::JSON::Array::ConstIterator it = array->begin();
    for (; it != array->end(); it++) {
        Poco::JSON::Object::Ptr Obj = it->extract<Poco::JSON::Object::Ptr>();
        Poco::Dynamic::Var net = Obj->get("networkTechnologyGeneration");
        Poco::Dynamic::Var netconstate = Obj->get("networkConnectionState");
        Poco::Dynamic::Var netregstate = Obj->get("networkRegistrationState");
        Poco::Dynamic::Var sigquality = Obj->get("signalQuality");
//            netstr += "\"" + net.toString() + "\"" + ",";
//			netconstatestr += "\"" + netconstate.toString() + "\"" + ",";
//			netregstatestr += "\"" + netregstate.toString() + "\"" + ",";
//			sigqualitystr += "\"" + sigquality.toString() + "\"" + ",";

        std::string  tmpnet;
        if(net.toString()=="gen4")
            tmpnet = "WAN_4G";
        else if(net.toString()=="gen2")
            tmpnet = "WAN_2G";
        else if(net.toString()=="gen3")
            tmpnet = "WAN_3G";
        else if(net.toString()=="gen5")
            tmpnet = "WAN_5G";
        else
            tmpnet = net.toString();

        if(!tmpnet.empty() && netstr.empty())
            netstr = "\"" + tmpnet + "\"" ;

        if(!netconstate.toString().empty() && netconstatestr.empty())
            netconstatestr = "\"" + netconstate.toString() + "\"";

        if(!netregstate.toString().empty() && netregstatestr.empty())
            netregstatestr = "\"" + netregstate.toString() + "\"";

        if(!sigquality.toString().empty() && sigqualitystr.empty())
            sigqualitystr = "\"" + sigquality.toString() + "\"";


//                netstr = "\"" + tmpnet + "\"";
//                netconstatestr = "\"" + netconstate.toString() + "\"";
//                netregstatestr = "\"" + netregstate.toString() + "\"";
//                sigqualitystr = "\"" + sigquality.toString() + "\"";
          }
//            netstr = "["+ netstr.substr(0, netstr.length() - 1) + "]";
//            netconstatestr = "["+ netconstatestr.substr(0, netconstatestr.length() - 1) + "]";
//            netregstatestr = "["+ netregstatestr.substr(0, netregstatestr.length() - 1) + "]";
//            sigqualitystr = "["+ sigqualitystr.substr(0, sigqualitystr.length() - 1) + "]";


            if( netstr.empty())
                netstr = "\"\"" ;
            if( netconstatestr.empty())
                netconstatestr = "\"\"" ;
            if( netregstatestr.empty())
                netregstatestr = "\"\"" ;
            if( sigqualitystr.empty())
                sigqualitystr = "\"\"" ;
//    netstr=getStaData(netstr);
//	netconstatestr=getStaData(netconstatestr);
//	netregstatestr=getStaData(netregstatestr);
//	sigqualitystr=getStaData(sigqualitystr);

    std::cout << "net===" << netstr << std::endl;
    std::cout << "netconstatestr===" << netconstatestr << std::endl;
    std::cout << "netregstatestr===" << netregstatestr << std::endl;
    std::cout << "sigqualitystr===" << sigqualitystr << std::endl;
    return 0;
}


