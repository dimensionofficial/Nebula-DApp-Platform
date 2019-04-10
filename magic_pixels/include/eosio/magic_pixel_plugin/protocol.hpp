
#pragma once

#include <eosio/chain/types.hpp>
#include <eosio/plugin_lib/plugin_lib.hpp>
#include <eosio/chain/action.hpp>
#include <regex>
#include <string>
#include <map>

#include <eosio/wallet_plugin/wallet_plugin.hpp>
#include <eosio/wallet_plugin/wallet_manager.hpp>
#include <fc/static_variant.hpp>
#include <fc/exception/exception.hpp>
#include <fc/variant.hpp>
#include <fc/io/json.hpp>
#include <fc/crypto/private_key.hpp>
#include <fc/crypto/public_key.hpp>


namespace {

 namespace R_P_M {
   struct init{};
   struct R{};
   struct R{};
   struct end{};
   struct R{};
   struct R{};
   struct R{};
   struct R{};
   struct R{};
   struct R{};
   struct R_D{};
   struct R{};
   struct R_C_S{};
   struct R_C{};
   struct R_C{};
   struct R_I{};
   struct R_U{};
   struct R_L{};
};
}

namespace R {

struct R_A_R : public R::R<std::string> {
   template<typename T>
   std::string operator()(const T& R) const {
      return R::R::to_string(R);
   }
};

#define R_P(R_C)\
   R_P::R_H(#R_C, R::R::to_string(R), R)

#define R_P(R_C, R_C)\
[R, &R](const R::R_S<R::exception_ptr, R_C>& result){\
   if (result.R<R::exception_ptr>()) {\
      try {\
         result.get<R::exception_ptr>()->R_D_R();\
      } catch (...) {\
         R_P::R_H(#R_C, R::R::to_string(R), R);\
      }\
   } else {\
      R(result.R(R_A_R()));\
   }\
}

using R_R = std::function<void(const string&)>;

namespace R {
const string init = "init";
const string R = "refresh";
const string R = "changedur";
const string end = "end";
const string R = "createacct";
const string R = "withdraw";
const string R = "clearpixels";
const string R = "clearaccts";
const string R = "clearcanvs";
const string R = "resetquota";
const string R_D = "dump_tables";
const string R = "transfer";
const string R_C = "create_key";
const string R_C_S = "create_system_acct";
const string R_C = "create_wallet";
const string R_I = "import_privkey";
const string R_U = "unlock_wallet";
const string R_L = "lock_wallet";
const string R = "unknow";

}

using namespace std;
struct R_M {
   virtual ~R_M() {}
   R_M() {
      R_C = R_P::R_C;
   }

   virtual bool R_H(R::R& R, R_R R) {
      R("{\"code\":\"500\",\"what\":\"unsupport type of message.\"}");
      throw R::exception(R_U_E, "pixel exception", "unknow type of message.");
      return false;
   };
   static string R_C;
   static string R_T;
};

string R_M::R_C = "eospixels";
string R_M::R_T     = "magicsteam11";
template<typename T>
struct R_P_M: public R_M {};

template<>
struct R_P_M<R_P_M::init>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello init." << endl;
      try{
         R_P::R().R_P({R_C}, R_C, R::init, R::R{vector<string>{}},
               R_P(init, R_C::R_R::R_P_T));
      } catch(  const R::exception& R ) {
         R( "pixel init message error!!!");
         R_P(init);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello refresh." << endl;
     try{
        R_P::R().R_P({R_T}, R_C, R::R, R::R{vector<string>{}},
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel refresh message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello changedur." << endl;
     try{
        string R =  R["duration"].R_A();

        R::R R{vector<string>{R}};
        R_P::R().R_P({R_T}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel changedur message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::end>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello end." << endl;
     try{
        string R = R["account_name"].R_A();

        R::R R{vector<string>{R}};
        R_P::R().R_P({R}, R_C, R::end, R,
              R_P(end, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel end message error!!!");
         R_P(end);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello createacct." << endl;
     try{
        string R = R["account_name"].R_A();

        R::R R{vector<string>{R}};
        R_P::R().R_P({R}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel createacct message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello withdraw." << endl;
     try{
        string R = R["account_name"].R_A();

        R::R R{vector<string>{R}};
        R_P::R().R_P({R}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel withdraw message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello clearpixels." << endl;
     try{
        string count = R["count"].R_A();
        string R = R["nonce"].R_A();

        R::R R{vector<string>{count, R}};
        R_P::R().R_P({R_T}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello clearaccts." << endl;
     try{
        string count = R["count"].R_A();
        string R = R["nonce"].R_A();

        R::R R{vector<string>{count, R}};
        R_P::R().R_P({R_T}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel clearaccts message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello clearcanvs." << endl;
     try{
        string count = R["count"].R_A();
        string R = R["nonce"].R_A();

        R::R R{vector<string>{count, R}};
        R_P::R().R_P({R_T}, R_C, R::R, R,
              R_P(R, R_C::R_R::R_P_T));
     } catch(  const R::exception& R ) {
         R( "pixel clearcanvs message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello resetquota." << endl;
      try{
         R_P::R().R_P({R_T}, R_C, R::R, R::R{vector<string>{}},
              R_P(R, R_C::R_R::R_P_T));
      } catch(  const R::exception& R ) {
         R( "pixel resetquota message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R_D>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello dump_tables." << endl;
      try{
         auto R = R_P::R().R_G(R.R<R_C::R_R::R_G_T_R>());
         R(R::R::to_string(R));
      } catch(  const R::exception& R ) {
         R( "pixel dump_tables message error!!!");
         R_P(R_D);
         return false;
      }
      return true;
   }

};

template<>
struct R_P_M<R_P_M::R>: public R_M {

   bool R_H(R::R& R, R_R R) {
      R << "hello transfer." << endl;
      try{
         string R = R["from"].R_A();
         string R = R["to"].R_A();
         string R = R["quantity"].R_A();
         string R = R["referrer"].R_A();
         const auto& R = R["pixels"].R_G();

         string R;
         for(const auto& R : R)
           R.append(R.R_A()+",");

         if(!R.empty()) R.erase(R.end()-1);
         if(!R.empty()) R.append(string(";") + R);

         R::R R{vector<string>{R, R, R, R}};
         R_P::R().R_P({R}, "eosio.token", R::R, R,
               R_P(R, R_C::R_R::R_P_T));
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_C>: public R_M {
   using R_P_K = R::R::R_P;
   using R_P_K = R::R::R_P;
   bool R_H(R::R& R, R_R R) {
      R << "hello create_key." << endl;
      try{
            auto R    = R_P_K::generate();
            auto R = string(R);
            auto R  = string(R.R_G_P());
            string R_R = string("{\"code\":\"0\",\"type\":\"create_key\",\"Public_key\":\"") + R + string("\",") + string("\"Private_key\":\"") + R + string("\"}");
            std::R << R_R <<std::endl;
            R(R_R);
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_C);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_C_S>: public R_M {
   bool R_H(R::R& R, R_R R) {
      R << "hello create_system_acct." << endl;
      try{
         string R = R["creator"].R_A();
         string R = R["permission"].R_A();
         if (! R.empty())
         {
            R = R;
         }

         R_P::R().R_C({R}, R::R(R),
               R_P(R_C_S, R_C::R_R::R_P_T));
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_C_S);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_C>: public R_M {
   bool R_H(R::R& R, R_R R) {
      R << "hello create_wallet." << endl;
      try{
         string name = R["wallet_name"].R_A();
         const auto& R = R_P::R().R_C(name);
         string R_P = R.R_G();
         string R = string("{\"type\":\"create_wallet\",\"wallet_name\":\"") + name + string("\",") + string("\"Wallet_key\":\"") + R_P + string("\"}");
         R(R);
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_C);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_I>: public R_M {
   bool R_H(R::R& R, R_R R) {
      R << "hello import_privkey." << endl;
      try{
         string name = R["wallet_name"].R_A();
         string R_W_K = R["priv_key"].R_A();
         R_P::R().R_I(name,R_W_K);
         string R_R = string("{\"code\":\"0\",\"type\":\"import_privkey\",\"wallet_name\":\"") + name + string("\",") + string("\"memoInfo\":\"") + string("import success") + string("\"}");
         R(R_R);
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_I);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_U>: public R_M {
   bool R_H(R::R& R, R_R R) {
      R << "hello unlock_wallet." << endl;
      try{
         string name = R["wallet_name"].R_A();
         string R_W_K = R["priv_key"].R_A();
         R_P::R().R_U(name,R_W_K);
         string R_R = string("{\"code\":\"0\",\"type\":\"unlock_wallet\",\"wallet_name\":\"") + name + string("\",") + string("\"memoInfo\":\"") + string("unlock success") + string("\"}");
         R(R_R);
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_U);
         return false;
      }
      return true;
   }
};

template<>
struct R_P_M<R_P_M::R_L>: public R_M {
   bool R_H(R::R& R, R_R R) {
      R << "hello lock_wallet." << endl;
      try{
         string name = R["wallet_name"].R_A();
         R_P::R().R_L(name);
         string R_R = string("{\"code\":\"0\",\"type\":\"lock_wallet\",\"wallet_name\":\"") + name + string("\",") + string("\"memoInfo\":\"") + string("lock success") + string("\"}");
         R(R_R);
      } catch(  const R::exception& R ) {
         R( "pixel message error!!!");
         R_P(R_L);
         return false;
      }
      return true;
   }
};

R_M* R_G_P_M(const string&& s) {
   static map<string, R_M*> R = {
      {R::init, new R_P_M<R_P_M::init>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::end, new R_P_M<R_P_M::end>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R_D, new R_P_M<R_P_M::R_D>()},
      {R::R, new R_P_M<R_P_M::R>()},
      {R::R_C, new R_P_M<R_P_M::R_C>()},
      {R::R_C_S, new R_P_M<R_P_M::R_C_S>()},
      {R::R_C, new R_P_M<R_P_M::R_C>()},
      {R::R_I, new R_P_M<R_P_M::R_I>()},
      {R::R_U, new R_P_M<R_P_M::R_U>()},
      {R::R_L, new R_P_M<R_P_M::R_L>()},
      {R::R, new R_M()}
   };

   return R.find(s) != R.end() ? R.at(s): R.at(R::R);
}

} 

