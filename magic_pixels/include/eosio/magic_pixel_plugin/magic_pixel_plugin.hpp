



#pragma once
#include <appbase/application.hpp>
#include <eosio/chain_plugin/chain_plugin.hpp>

namespace R {
   using namespace R;

   class R_P : public R::R<R_P>
   {
      public:
        R_P();
        virtual ~R_P();

        R((R_C))
        virtual void R_S_P(R_O& R, R_O& R) override;

        void R_P(const R_V& R);
        void R_P();
        void R_P();

        static void R_H(const char *R_C, const string& R, std::function<void(const std::string&)> R);

      public:
        static string R_C;
        static string R_T;

      private:
        std::unique_ptr<class R_P_P> R;
   };

   string R_P::R_C = "eospixels";
   string R_P::R_T     = "magicsteam11";

}

