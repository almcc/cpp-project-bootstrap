#define WIN32_LEAN_AND_MEAN  /* required by xmlrpc-c/server_abyss.hpp */

#include <cassert>
#include <stdexcept>
#include <iostream>
#include <unistd.h>

using namespace std;

#include <xmlrpc-c/base.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/server_abyss.hpp>


class sampleAddMethod : public xmlrpc_c::method {
public:
    sampleAddMethod() {
        this->_signature = "i:ii";
        this->_help = "This method adds two integers together";
    }
    void
    execute(xmlrpc_c::paramList const& paramList,
            xmlrpc_c::value *   const  retvalP) {

        int const addend(paramList.getInt(0));
        int const adder(paramList.getInt(1));

        xmlrpc_env env;

        xmlrpc_env_init(&env);

        xmlrpc_value * myArrayP;
        xmlrpc_value * itemP;
        xmlrpc_value * itemB;

        myArrayP = xmlrpc_array_new(&env);

        itemP = xmlrpc_string_new(&env, "This is array item 0");
        itemB = xmlrpc_int_new(&env, addend + adder);

        xmlrpc_array_append_item(&env, myArrayP, itemP);
        xmlrpc_array_append_item(&env, myArrayP, itemB);

        xmlrpc_DECREF(itemP);
        xmlrpc_DECREF(itemB);

        xmlrpc_value * myStructP;
        xmlrpc_value * memberValueP;
        myStructP = xmlrpc_struct_new(&env);
        memberValueP = xmlrpc_double_new(&env, 19.2);
        xmlrpc_struct_set_value(&env, myStructP, "temperature", memberValueP);
        xmlrpc_DECREF(memberValueP);
        xmlrpc_array_append_item(&env, myArrayP, myStructP);

        paramList.verifyEnd(2);

        *retvalP = myArrayP;
    }
};



int
main(int           const argc,
     const char ** const argv) {

    xmlrpc_c::registry myRegistry;

    xmlrpc_c::methodPtr const sampleAddMethodP(new sampleAddMethod);

    myRegistry.addMethod("sample.add", sampleAddMethodP);

    xmlrpc_c::serverAbyss myAbyssServer(
        myRegistry,
        8080,              // TCP port on which to listen
        "/tmp/xmlrpc_log"  // Log file
        );

    myAbyssServer.run();
    // xmlrpc_c::serverAbyss.run() never returns
    assert(false);

    return 0;
}