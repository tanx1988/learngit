//
// Created by thh on 2020/9/2.
//
#include <iostream>
#include "Poco/JSON/Parser.h"

int main() {
    std::string jsonString = R"(
{
  "data" : [
    {
      "iccid" : "89860919730065126552",
      "id" : "35989683-dc5a-58ca-a63b-9effe29491df",
      "imei" : "460093003750593",
      "imsi" : [
        "460093003750593",
        "460093003754532",
        "3566663003750593",
""
      ],
      "name" : "eSIM",
      "uri" : "\/onlinestate\/simData\/35989683-dc5a-58ca-a63b-9effe29491df"
    }
  ,
    {
      "iccid" : "89860919730065126552",
      "id" : "35989683-dc5a-58ca-a63b-9effe29491df",
      "imei" : "110093003750593",
      "imsi" : [
        "460093003750593",
        "460093003754532",
        "3566663003750593",
""
      ],
      "name" : "eSIM",
      "uri" : "\/onlinestate\/simData\/35989683-dc5a-58ca-a63b-9effe29491df"
    }
  ],
  "status" : "ok"
})";
    Poco::JSON::Parser parser;
    Poco::Dynamic::Var result;
    parser.reset();
    result = parser.parse(jsonString);
    if (result.isEmpty()) {
        std::cout << "result ==empty" << std::endl;
    }
    std::string imeistr;
    Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
    Poco::JSON::Array::Ptr array = object->getArray("data");
    Poco::JSON::Array::ConstIterator it = array->begin();
    for (; it != array->end(); it++) {
        Poco::JSON::Object::Ptr Obj = it->extract<Poco::JSON::Object::Ptr>();
        Poco::Dynamic::Var imei = Obj->get("ei");
        if(imei.isEmpty())
        {
            std::cout << "no key" << std::endl;
            return -1;
        }
        if(!imei.toString().empty() && imeistr.empty())
        {
            imeistr = "\"" + imei.toString() + "\"" ;
            break;
        }

    }
    if( imeistr.empty())
        imeistr = "\"\"" ;
//    imeistr = "["+ imeistr.substr(0, imeistr.length() - 1) + "]";
    std::cout << "imei===" << imeistr << std::endl;
    return 0;
}
