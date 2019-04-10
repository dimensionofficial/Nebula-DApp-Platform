
#include "include/eosio/pixel_plugin/pixel_plugin.hpp"
#include "include/eosio/pixel_plugin/protocol.hpp"

#include <eosio/chain/types.hpp>

#include <eosio/chain/controller.hpp>
#include <eosio/chain/exceptions.hpp>
#include <eosio/chain/block.hpp>
#include <eosio/chain/plugin_interface.hpp>
#include <eosio/producer_plugin/producer_plugin.hpp>
#include <eosio/utilities/key_conversion.hpp>
#include <eosio/chain/contract_types.hpp>
#include <eosio/http_plugin/http_plugin.hpp>

#include <fc/network/message_buffer.hpp>
#include <fc/network/ip.hpp>
#include <fc/io/json.hpp>
#include <fc/io/raw.hpp>
#include <fc/log/appender.hpp>
#include <fc/container/flat.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/crypto/rand.hpp>
#include <fc/exception/exception.hpp>

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/host_name.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/intrusive/set.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace R::R::R_P::R;

namespace R {
   extern std::R_U<std::string,R>& R_G_L();
}

namespace R {
   static R::R_A& R__P = app().R_R<R_P>();

   using std::vector;
   using std::deque;
   using std::shared_ptr;

   using R::R::R::R;
   using R::R::R::R_A;
   using R::R::R::R_H;
   using R::R::R;
   using R::R_M_I;

   using R::R_T;
   using R::R_T_P;
   using R::R_B_S;


   class R;

   using R_P = std::shared_ptr<R>;
   using R_P = std::weak_ptr<R>;
   using R_R = std::function<void(int,string)>;
   using R_S = shared_ptr<R::R>;

   class R_P_P {
   public:
      unique_ptr<R::R>        R;
      R::R                    R_L;
      uint32_t                R_N = 0;

      std::map<R::R_P_K,
               R::R_P_K> R_P; 


      R_P R_F( string R )const;

      std::set< R_P >       R;
      bool                  R = false;

      unique_ptr<R::R::R_S> R_T;
      R::R::R_S::R   R_R_E;

      R_C*                 R_C = nullptr;
      int                  R_S = 0;
      shared_ptr<R::R>     R;

      bool R_S( R_P c );
      void R_S_L( );
      void R_S_R( R_P c);

      void   close( R_P c );


      void R_A_B(const R_B_S&);
      void R_A(const R_B_S&);
      void R_I(const R_B_S&);
      void R_A(const R_T_M&);
      void R_A(const R_T_T&);
      void R_A(const R_H&);

      bool R_I( const R_H &R);

      void R_H( R_P c, const R_H &R);

      void R_I_T(R_P c);

      struct R_T {
         uint64_t count;
         uint32_t R_B;
         string id;
         string type;
         R_P s;
         bool operator<(const R_T &other) const {
            return R_B < other.R_B;
         }
      };
      std::R<R_T> R_T;

      std::R<R_T>& R_G_T() { return R_T; }
      R::R<std::pair<uint32_t, string>> R_T_I_F(const string& R);
   };

   const R::string R_L("pixel_plugin_impl");
   R::R R;
   std::string R_P;

#define R_P( R, FORMAT, ... ) \
  R_F_M_M \
   if( R.R_I( R::R_L::R ) ) \
      R.log( R_F_L( R, R_P + FORMAT, R_V_A__ (R->R_G_L()) ) ); \
  R_F_M_M

#define R_P( R, FORMAT, ... ) \
  R_F_M_M \
   if( R.R_I( R::R_L::R ) ) \
      R.log( R_F_L( R, R_P + FORMAT, R_V_A__ (R->R_G_L()) ) ); \
  R_F_M_M

#define R_P( R, FORMAT, ... ) \
  R_F_M_M \
   if( R.R_I( R::R_L::R ) ) \
      R.log( R_F_L( R, R_P + FORMAT, R_V_A_ (R->R_G_L()) ) ); \
  R_F_M_M

#define R_P( R, FORMAT, ... ) \
  R_F_M_M \
   if( R.R_I( R::R_L::error ) ) \
      R.log( R_F_L( error, R_P + FORMAT, R_V_A__ (R->R_G_L())) );   R_F_M_M

   static R_P_P *R_M;

   


   constexpr auto     R_D_S_B_S = 4;
   constexpr auto     R_D_S_B = 1024*1024*R_D_S_B_S;
   constexpr auto     R_D_M = 25; 
   constexpr auto     R_D_M_N_P = 1;
   constexpr auto     R_D_C_R = 30;
   constexpr auto     R_D_T_E = std::R::R(3);
   constexpr auto     R_D_R_E = std::R::R(5);
   constexpr auto     R_D_S_F = 100;
   constexpr uint32_t  R_D_M_J = 1500; 
   constexpr bool     R_L_M = false;

   constexpr auto     R_M_L = 4;
   constexpr auto     R_M_C = 8;
   constexpr auto     R_M_H = R_M_L + R_M_C;

   class R : public std::enable_shared_from_this<R> {
   public:
      explicit R( string R );

      explicit R( R_S s );
      ~R();
      void R();

      R_S              R;

      R::R_M<1024*1024>    R_P_M;
      R::R<std::size_t>    R_O_R;
      vector<char>         R_R;

      string                  R_P;
      unique_ptr<R::R::R_S> R_R;

      const string R_P() {return R_P;}
      bool R();
      void close();



      void R_F();

      bool R_P_N(R_P_P& R, uint64_t count, uint32_t R_M);
      bool R_S(uint64_t count, const string& R);

      R::R<R::R_V> R___L;
      const R::R_V& R_G_L()  {
         if (!R___L) {
            R::system::error_code R;
            auto R = R->R_R(R);
            string R = R ? "<unknown>" : R.address().to_string();
            string R = R ? "<unknown>" : std::to_string(R.R());

            auto R = R->R_L(R);
            string R = R ? "<unknown>" : R.address().to_string();
            string R = R ? "<unknown>" : std::to_string(R.R());

            R___L.emplace(R::R_M_V()
               ("_name", R_P())
               ("_ip", R)
               ("_port", R)
               ("_lip", R)
               ("_lport", R)
            );
         }
         return *R___L;
      }
   };


   R::R( string R )
      : R( std::make_shared<R::R>( std::ref( app().R_G_I() ))),
        R_P(R),
        R_R()
   {
      R( "created connection to ${n}", ("n", R) );
      R();
   }

   R::R( R_S s )
      : R( s ),
        R_P(),
        R_R()
   {
      R( "accepted network connection" );
      R();
   }

   R::~R() {}

   void R::R() {
      R_R.reset(new R::R::R_S(app().R_G_I()));
   }

   bool R::R() {
      return (R && R->R_I());
   }

   void R::close() {
      if(R) {
         R->close();
      }
      else {
         R("no socket to close!");
      }
      R_P_M.reset();
   }

   bool R::R_P_N(R_P_P& R, uint64_t count, uint32_t R_M) {
      try {
         auto index = R_P_M.R_R();
         R_R.resize(R_M);

         R_P_M.peek(R_R.data(), R_M, index);
         R_P_M.R_A_R(R_M);

         string s(R_R.data(), R_R.size());
         std::R << "rev_message_body = " << s << std::endl;
         R::R R = R::R::R_F(s);

          R_M* R = R_G_P_M(R["type"].R_A());
         
         string R_T = R["type"].R_A();     

         if((R_T == string("dump_tables")) ) 
                     
                     std::R << "[ **** Receive counter  =" << count  << " **** " << std::endl;    

          R_P R(shared_from_this());
          R->R_H(R, [count, R, R_T, this](const string& R ) {
             try {
                auto s = R.lock();
                if(!s) throw R::exception();
                auto R = R_M->R_T_I_F(R);
               
               if((R_T == string("transfer")) && R) 
                     
                     std::R << "[ inserting: block_num  =" << R->first << "\t txs_id = "<< R->second << std::endl;

                if(R) {
                   R_M->R_G_T().insert(R_P_P::R_T{count, R->first, R->second, R_T, s});

                   string R = string("{\"code\":\"0\",\"cmd_type\":\"") + R_T + "\",\"transaction_id\":\"" + R->second + "\",\"confirmed\":\"waitting\"}";
                   s->R_S(count, R);
                }else {
                   s->R_S(count, R);
                }
             }
             catch(const std::exception &R) {
                R("Exception in pixel handle_message to ${s}", ("s",R.what()));
                close();
             }
             catch(const R::exception &R) {
                R("Exception in pixel handle_message to ${s}", ("s",R.to_string()));
                close();
             }
             catch(...) {
                R("Exception in pixel handle_message." );
                close();
             }
          });
      } catch(  const R::exception& R ) {
         R((R.R_T_D() ));
         R.close( shared_from_this() );
         return false;
      }
      return true;
   }

   bool R::R_S(const uint64_t count, const string& R) {
       if(R.empty()) {
          R("Send msg is empty." );
          return false;
       }

       int R = R.size();
       shared_ptr<vector<char>> R = make_shared<vector<char>>();
       R->reserve(R_M_H+R);

       for( int R = 0; R < R_M_L; ++R) { R->push_back(char(R >> (R*8) & 0xff)); }
       for( int R = 0; R < R_M_C; ++R) { R->push_back(char(count >> (R*8) & 0xff)); }
       for(auto& c : R) R->push_back(c);

       R::R::R_A( *R,
          R::R::R( R->data(), R->size()),
          [R](const R::system::error_code& R, size_t R_B) {
             if(R) {
                R("psession send error. the send len size: ${size}, ${error}, ${buf_size}",
                      ("size", R_B)("error",R.message())("buf_size", R->size()));
                return;
             }
          }
       );

      return true;
   }

   R::R<std::pair<uint32_t, string>> R_P_P::R_T_I_F(const string& R) {
      R::R<std::pair<uint32_t, string>> R;

      std::stringstream R(R);
      R::R_P::R R;
      R::R_P::R R;
      R::R_P::R_R<R::R_P::R>(R, R);

      if(R.find("transaction_id") != R.R_N() && R.find("processed") != R.R_N()) {
         string id = R.get<string>("transaction_id");

         R = R.R_G("processed");
         if(R.find("block_num") != R.R_N()) {
            uint32_t R_B = R.get<uint32_t>("block_num");
            R.emplace(std::make_pair(R_B, id));
         }
      }

      return R;
   }

   bool R_P_P::R_S( R_P R ) {
      R::R::R::R::R_N R( true );
      R::system::error_code R;
      R->R->R_S( R, R );
      if (R) {
         R( "connection failed to ${peer}: ${error}",
               ( "peer", R->R_P())("error",R.message()));
         close(R);
         return false;
      }
      else {
         R_S_R( R );
         ++R_S;
         return true;
      }
   }

   void R_P_P::R_S_L( ) {
      auto R = std::make_shared<R::R>( std::ref( app().R_G_I() ) );
      R->R_A( *R, [R,this]( R::system::error_code R ) {
            if( !R ) {
               uint32_t R = 0;
               uint32_t R_F = 0;
               auto R = R->R_R(R).address();
               std::R << "The peer-addr is " << R << std::endl;
               if (R) {
                  R_F(R,"Error getting remote endpoint: ${m}",("m", R.message()));
               }
               else {
                  ++R_N;
                  R_P c = std::make_shared<R>( R );
                  R.insert( c );
                  R_S( c );
               }
            } else {
               R( "Error accepting connection: ${m}",( "m", R.message() ) );
               
               switch (R.value()) {
                  case R:
                  case EMFILE:
                  case ENFILE:
                  case R:
                  case ENOMEM:
                  case R:
                     break;
                  default:
                     return;
               }
            }
            R_S_L();
         });
   }

   void R_P_P::R_S_R( R_P R ) {

      try {
         if(!R->R) {
            return;
         }
         R_P R_W = R;

         std::size_t R_M = R->R_O_R ? *R->R_O_R : R_M_H;
         auto R_C = [R_M](R::system::error_code R, std::size_t R_B) -> std::size_t {
            if (R || R_B >= R_M ) {
               return 0;
            } else {
               return R_M - R_B;
            }
         };

         R::R::R_A(*R->R,
            R->R_P_M.R_G_B_S_F_B_A(), R_C,
            [this,R_W]( R::system::error_code R, std::size_t R_B ) {
               auto R = R_W.lock();
               if (!R) {
                  return;
               }

               R->R_O_R.reset();

               try {
                  if( !R ) {
                     if (R_B > R->R_P_M.R_B_T()) {
                        R("async_read_some callback: bytes_transfered = ${bt}, buffer.bytes_to_write = ${btw}",
                             ("bt",R_B)("btw",R->R_P_M.R_B_T()));
                     }
                     std::R << "bytes_transferred = " << R_B << std::endl;  
                     R->R_P_M.R_A_W(R_B);
                     while (R->R_P_M.R_B_T() > 0) {
                        uint32_t R_B_I = R->R_P_M.R_B_T();

                        if (R_B_I < R_M_H) {
                           R->R_O_R.emplace(R_M_H - R_B_I);
                           std::R << " bytes_in_buffer < message_header_size " << std::endl;
                           break;
                        } else {
                           uint32_t R_M;
                           auto index = R->R_P_M.R_R();
                           R->R_P_M.peek(&R_M, sizeof(R_M), index);
                           if(R_M > R_D_S_B*2 || R_M == 0) {
                              R::system::error_code R;
                              R("incoming message length unexpected (${i}), from ${p}", ("i", R_M)("p",R::R_L<std::string>(R->R->R_R(R))));
                              close(R);
                              return;
                           }

                           auto R_T_M = R_M + R_M_H;

                           if (R_B_I >= R_T_M) {
                              R->R_P_M.R_A_R(R_M_L);

                              uint64_t count;
                              auto index = R->R_P_M.R_R();
                              R->R_P_M.peek(&count, sizeof(count), index);

                              R->R_P_M.R_A_R(R_M_C);
                              if (!R->R_P_N(*this, count, R_M)) {
                                 return;
                              }
                           } else {
                              auto R_O_M = R_T_M - R_B_I;
                              auto R_A_B = R->R_P_M.R_B_T();
                              if (R_O_M > R_A_B) {
                                 R->R_P_M.R_A( R_O_M - R_A_B );
                              }

                              R->R_O_R.emplace(R_O_M);
                              break;
                           }
                        }
                     }
                     R_S_R(R);
                  } else {
                     auto R = R->R_P();
                     if (R.value() != R::R::error::eof) {
                        R( "Error reading message from ${p}: ${m}",("p",R)( "m", R.message() ) );
                     } else {
                        R( "Peer ${p} closed connection",("p",R) );
                     }
                     close( R );
                  }
               }
               catch(const std::exception &R) {
                  string R = R ? R->R_P() : "no connection name";
                  R("Exception in handling read data from ${p} ${s}",("p",R)("s",R.what()));
                  close( R );
               }
               catch(const R::exception &R) {
                  string R = R ? R->R_P() : "no connection name";
                  R("Exception in handling read data ${s}", ("p",R)("s",R.to_string()));
                  close( R );
               }
               catch (...) {
                  string R = R ? R->R_P() : "no connection name";
                  R( "Undefined exception hanlding the read data from connection ${p}",( "p",R));
                  close( R );
               }
            } );
      } catch (...) {
         string R = R ? R->R_P() : "no connection name";
         R( "Undefined exception handling reading ${p}",("p",R) );
         close( R );
      }
   }

   void R_P_P::R_I_T(R_P c) {
      R_T->R_E_F( R_R_E);
      R_T->R_A( [this](R::system::error_code R) {
         if( !R) {
         }
         else {
            R( "Error connection: ${m}",( "m", R.message()));
         }
      });
   }

   void R_P_P::R_A_B(const R_B_S& R) {
      
   }

   void R_P_P::R_A(const R_T_M& R) {
      
   }

   void R_P_P::R_A(const R_T_T& R) {
      
   }

   void R_P_P::R_A(const R_H& R) {
      
   }

   void R_P_P::R_I(const R_B_S&R) {}

   void R_P_P::close( R_P c ) {
      if( c->R_P.empty( ) && c->R->R_I() ) {
         if (R_N == 0) {
            R_F( R, "num_clients already at 0");
         }
         else {
            --R_N;
         }
      }
      c->close();
   }

   void R_P::R_P( const R_V& R ) {
      R("Initialize pixel plugin");
      try {
          if( R.count( "pixel-contract-name" ))
            R_C = R.at( "pixel-contract-name" ).R<string>();

          R->R_R_E = R_D_R_E;
          R->R = std::make_shared<R::R>( std::ref( app().R_G_I()));

          R::R::R R( R::R(), "0.0.0.0", "10003");

         R->R_L = *R->R->R( R );

         R->R.reset( new R::R( app().R_G_I()));
         R->R_C = app().R_F<R_C>();

      } R_F_L_A()
   }

   void R_P::R_P() {
      if( R->R ) {
         R->R->open(R->R_L.R());
         R->R->R_S(R::R::R_R(true));
         try {
           R->R->bind(R->R_L);
         } catch (const std::exception& R) {
           R("pixel_plugin::plugin_startup failed to bind to port ${port}",
             ("port", R->R_L.R()));
           throw R;
         }
         R->R->R();
         R("starting listener...");
         R->R_S_L();
      }
      R::R&R = R->R_C->R();
      {
             R.R_A.R(  R::bind(&R_P_P::R_A, R.get(), _1));
      }
   }

   void R_P::R_P() {
      try {
         R( "shutdown.." );
         R->R = true;
         if( R->R ) {
            R( "close acceptor" );
            R->R->close();

            R( "close ${s} connections",( "s",R->R.size()) );
            auto R = R->R;
            for( auto R : R ) {
               R->close( R);
            }

            R->R.reset(nullptr);
         }
         R( "exit shutdown" );
      }
      R_F_C_A()
   }

   void R_P::R_H(const char *R_C, const string& R, R_R R ) {
      static bool R_V = false;
      try {
         try {
            throw;
         } catch (R::R_U& R) {
            R_E R{401, "UnAuthorized", R_E::R_E(R, R_V)};
            R( R::R::to_string( R ));
         } catch (R::R_T& R) {
            R_E R{409, "Conflict", R_E::R_E(R, R_V)};
            R(R::R::to_string( R ));
         } catch (R::R_E& R) {
            R_E R{422, "Unprocessable Entity", R_E::R_E(R, R_V)};
            R(R::R::to_string( R ));
            R("Bad arguments: ${cmd}", ("cmd", R));
         } catch (R::exception& R) {
            R_E R{500, "Internal Service Error", R_E::R_E(R, R_V)};
            R(R::R::to_string( R ));
            if (R.code() != R::R_G_N_U::R_C ) {
               R( "FC Exception encountered while processing pixel.${call}", ( "call", R_C ));
               R( "Exception Details: ${e}", ("e", R.R_T_D()));
            }
         } catch (std::exception& R) {
            R_E R{500, "Internal Service Error", R_E::R_E(R::exception( R_F_L( error, R.what())), R_V)};
            R( R::R::to_string( R ));
            R( "STD Exception encountered while processing pixel.${call}", ( "call", R_C ));
            R( "Exception Details: ${e}", ("e", R.what()));
         } catch (...) {
            R_E R{500, "Internal Service Error",
               R_E::R_E(R::exception( R_F_L( error, "Unknown Exception" )), R_V)};
            R(R::R::to_string( R ));
            R( "Unknown Exception encountered while processing ${call}", ( "call", R_C ));
         }
      } catch (...) {
         R_E R{500, "Internal Service Error", R_E::R_E(R::exception( R_F_L( error, "unknow")), R_V)};
         R(R::R::to_string( R ));
         std::R << "Exception attempting to handle exception for pixel." << R_C << std::endl;
      }
   }


   R_P::R_P():R( new R_P_P ) { R_M = R.get();}
   R_P::~R_P() {}

   void R_P::R_S_P( R_O&  , R_O& R )
   {
      R.R_A()( "pixel-contract-name", R::value<string>()->R_D( "eospixels" ), "The name of pixel contract.");
      R.R_A()( "pixel-team-name", R::value<string>()->R_D( "magicsteam11" ), "The name of pixel team.");
   }
}

