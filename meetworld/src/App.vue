<template>
  <div id="app">
    <!--<GlobalProgress v-show="globalProgressVisible" :progress="globalProgressValue" />-->
    <Loading v-show="globalProgressVisible" loadText="loading ..." />
    <!--<GlobalSpinner v-show="!globalProgressVisible && globalSpinnerVisible" />-->
    <Loading v-show="!globalProgressVisible && globalSpinnerVisible" loadText="loading ..." />
    <!--<div class="app-nav is-hidden-mobile" v-show="!tokenShow">-->
      <!-- 我的地标 -->
    <myPortal v-if="portalShow" :portalList="portalList" @closeMyPortal="closeMyPortal" />
    <!------------------------
    navigator
    --------------------------->
    <div class="app-nav is-hidden-mobile">
      <!-- 登录-->
      <!-- <button :class="['nav-item', 'button', 'is-white', 'is-small', 'is-rounded', 'is-outlined', { 'is-loading': isScatterLoggingIn }]"
        @click="loginScatterAsync"
        v-if="!scatterAccount && appLogin"
      >
        <b-icon icon="account" size="is-small" />&nbsp;{{$t('login')}}
      </button> -->
      <!--登出-->
      <!-- <button :class="['nav-item', 'button', 'is-white', 'is-small', 'is-rounded', 'is-outlined']"
        @click="logoutScatterAsync"
        v-if="isScatterConnected && scatterAccount"
      >
        <b-icon icon="account" size="is-small" />&nbsp;{{$t('logout')}} {{scatterAccount.name}}
      </button> -->
      <!-- <buuton @click="register">注册</buuton> -->
      <!-- <register v-show="isregister" v-on:registerchange="zidingyi($event)"/> -->
      <!--邀请按钮-->
      <!--<button :class="['nav-item', 'button', 'is-white', 'is-small', 'is-rounded', 'is-outlined']"-->
         <!--@click="changeInviteStatus"-->
         <!--v-if="scatterAccount"-->
      <!--&gt;-->
        <!--<b-icon icon="account" size="is-small" />&nbsp;{{$t('invite')}}-->
      <!--</button>-->

      <!--<b-modal :active.sync="isInviteDialogActive" has-modal-card>-->
        <!--<invite-modal></invite-modal>-->
      <!--</b-modal>-->
      <!--地图-->
      <!--<router-link v-if="modulesConfig[contractType].map" class="nav-item" to="/map">{{$t('map')}}</router-link>-->
      <!-- 登录注册 -->
      <a class="nav-item login" v-show="!myaccount" @click="loginShow=!loginShow" ><div>{{$t('login')}}/{{$t('register')}}</div></a>
      <a class="nav-item login" v-show="myaccount" @click="logout()">{{$t('logout')}}</a>
      <!--地球-->
      <!-- <router-link v-if="modulesConfig[contractType].map" class="nav-item" to="/"><div>{{$t('globe')}}</div></router-link> -->
      <!--通证-->
      <a v-if="modulesConfig[contractType].token" class="nav-item" @click="tokenShow=!tokenShow"><div>{{$t('token_view')}}</div></a>
      <!--关于-->
      <a class="nav-item" @click="aboutShow=!aboutShow"><div>{{$t('about_view')}}</div></a>
      <!--我的地标-->
      <a v-if="modulesConfig[contractType].map" class="nav-item" @click="taggleMyPortal"><div>{{$t('my_portal_nav')}}</div></a>
      <!-- 语言 -->
      
        <b-select v-model="i18nCode" :placeholder="$t('switch_lang')" >
          <option value="en">English</option>
          <!-- <option value="ja">日本語</option> -->
          <option value="ko">한국어</option>
          <!-- <option value="ru">русский</option> -->
          <option value="zh">简体中文</option>
          <option value="zh_tw">繁體中文</option>
        </b-select>

    </div>
    <!-- 登录注册面板 -->
      <login @goclose="closelogin()" v-if="loginShow"  class="loginView"/>
    <!--通证面板-->
    <Tokenview
      v-if="modulesConfig[contractType].token"
      :tokenShow="tokenShow"
      :mobileTokenShow="mobileTokenShow"
      :globalInfo="globalInfo"
      :dividendInfo="dividendInfo"
      :scatterAccount="scatterAccount"
      :balances="balances"
      :marketInfo="marketInfo"
      :stakedInfo="stakedInfo"
      @CloseTokenView="CloseTokenView"
      @CloseMobileTokenView="CloseMobileTokenView"
      @claim="claim"
      @stake="stake"
      @unstake="unstake"
      @refund="refund"
      @loginScatterAsync="loginScatterAsync"
      @buyCMU="buyCMU"
      @sellCMU="sellCMU"
      @vote="vote"
    />
    <!--关于面板-->
    <Aboutview
      :aboutShow="aboutShow"
      :mobileAboutShow="mobileAboutShow"
      @CloseAboutView="CloseAboutView"
      @CloseMobileAboutView="CloseMobileAboutView"
    />
    <!-- 注册/登录面板 -->

    <!-----------------------
    footer
    ------------------------->
    <div class="app-footer">
      <!--link-->
      <div class="footer-item is-hidden-mobile"><a target="_blank" href="https://twitter.com/DimensionChain"><b-icon icon="twitter" size="is-small" /></a></div>
      <div class="footer-item is-hidden-mobile"><a target="_blank" href="https://t.me/dimensionofficial"><b-icon icon="telegram" size="is-small" /></a></div>
      <div class="footer-item is-hidden-mobile"><a target="_blank" href="https://www.facebook.com/dimensionEON"><b-icon icon="facebook" size="is-small" /></a></div>
      <div class="footer-item is-hidden-mobile"><a target="_blank" href="https://github.com/dimensionofficial"><b-icon icon="github-circle" size="is-small" /></a></div>

      <div class="footer-item is-hidden-mobile">{{$t('cmu_creator')}}</div>
      <!--Powered By EOSIO-->
      <div class="footer-item is-hidden-mobile">{{$t('powered_by')}} <a target="_blank" >Dimension</a></div>
      <!--最后的买家-->
      <!-- <div class="footer-item" v-if="globalInfo && latestBuyerVisible">{{$t('last_buyer')}}: <b>{{ globalInfo.last }}</b> </div> -->
      <!--剩余时间-->
      <!-- <div class="footer-item" v-if="globalInfo && latestBuyerVisible">{{$t('count_down')}}: <b>{{ globalCountdown }}</b> </div> -->
      <!--奖池-->
      <!-- <div class="footer-item" v-if="globalInfo && latestBuyerVisible">
        {{$t('prize_pool')}}: <b>{{ globalInfo.pool | price('EON') }}</b>
        <b-tooltip
          :label="$t('app_FTextBubble')"
          position="is-top">
          <a href="https://kyubey.network/Token/CMU/exchange" target="_blank"><b-icon class="question-icon" pack="fas" type="is-white" icon="question-circle" size="is-middle" /></a>
        </b-tooltip>
      </div> -->
      <!--语言-->
      
      <!--选择公链-->
      <!-- <div class="footer-item is-hidden-mobile">
        <b-select class="is-inverted" v-model="updateContract" placeholder="选择公链" size="is-small" rounded>
          <option value="eos">EOS</option>
          <option value="bos">BOS</option>
        </b-select>
      </div> -->
    </div>
    <!---------------------
    移动端导航
    ----------------------->
    <!--菜单icon-->
    <!-- <a
      :class="['app-nav-burger', 'is-hidden-tablet', { 'is-active': mobileNavExpanded }]"
      v-show="navBurgerVisible"
    >
      <a @click="mobileNavExpanded = !mobileNavExpanded">
        <span aria-hidden="true"></span>
        <span aria-hidden="true"></span>
        <span aria-hidden="true"></span>
      </a>
      <button :class="['app-map-login', 'nav-item', 'button', 'is-white', 'is-small', 'is-rounded', 'is-outlined', { 'is-loading': isScatterLoggingIn }]"
        @click="loginScatterAsync"
        v-if="!scatterAccount && appLogin"
      >
        {{$t('login')}}
      </button>
    </a> -->
    <!--子菜单-->
    <slide-y-up-transition>
      <div>
        <div class="app-nav-expand is-hidden-tablet app-app-nav-expand" v-show="navBurgerVisible && mobileNavExpanded" @click="mobileNavExpanded=false"><!-- Nav Items on mobile -->
          <router-link v-if="modulesConfig[contractType].map" class="app-nav-expand-item" to="/map">Map</router-link>
          <!--地球-->
          <router-link v-if="modulesConfig[contractType].map" class="app-nav-expand-item" to="/">Globe</router-link>
          <!--我的地标-->
          <a class="app-nav-expand-item" v-if="modulesConfig[contractType].map" @click="taggleMyPortal">{{$t('my_portal_nav')}}</a>

          <!--<a class="app-nav-expand-item" v-if="scatterAccount" @click="changeInviteStatus"><b-icon icon="bank" size="is-small" />{{' '+$t('invite')}}</a>-->
          <!--关于-->
          <a class="app-nav-expand-item" @click="mobileAboutShow=!mobileAboutShow;">
            <b-icon class="question-icon" pack="fas" icon="question-circle" size="is-small"></b-icon>
            {{' '+$t('about_view')}}
          </a>
          <!--通证-->
          <!-- <a class="app-nav-expand-item" v-if="modulesConfig[contractType].token" @click="mobileTokenShow=!mobileTokenShow;"><b-icon icon="bank" size="is-small" />{{' '+$t('token_view')}}</a> -->
          <!--link start-->

          <!--link end-->
          <!--语言-->
          <!-- <div class="app-nav-expand-item" @click.stop>
            <b-select class="is-inverted" v-model="i18nCode" icon="translate" :placeholder="$t('switch_lang')"  rounded expanded>
              <option value="en">English</option>
              <option value="ja">日本語</option>
              <option value="ko">한국어</option>
              <option value="ru">русский</option>
              <option value="zh">简体中文</option>
              <option value="zh_tw">繁體中文</option>
            </b-select>
          </div> -->
        </div>
        <!--邀请面板-->
        <b-modal :active.sync="isInviteDialogActive" has-modal-card>
          <invite-modal></invite-modal>
        </b-modal>
      </div>
    </slide-y-up-transition>
    <!--路由-->
    <!-- <keep-alive include="map-view,globe-view"><router-view/></keep-alive> -->
    <globe-view></globe-view>
  </div>
</template>

<script>
import { mapActions, mapState } from 'vuex';
import Global from './Global.js';
import Aboutview from '@/views/About.vue';
import Tokenview from '@/views/Token.vue';
import getApi from '@/util/apis/index.js'
// import GlobalSpinner from '@/components/GlobalSpinner.vue';
import Loading from '@/components/Loading.vue';
// import GlobalProgress from '@/components/GlobalProgress.vue';
import InviteModal from '@/components/InviteModal.vue';
import myPortal from '@/components/landmark/myPortal.vue';
import login from '@/views/loginRegister.vue';
import globeView from '@/views/GlobeView.vue';

export default {
  name: 'App',
  components: {
    Loading,
    //  GlobalSpinner,
    //  GlobalProgress,
    Aboutview,
    Tokenview,
    InviteModal,
    myPortal,
    login,
    globeView
    // register
  },
  data: () => ({
    mobileNavExpanded: false,
    tokenShow: false,
    aboutShow: false,
    globalCountdown: '00:00:00',
    mobileTokenShow: false,
    mobileAboutShow: false,
    isRedeeming: false,
    isInviteDialogActive : false,
    appLogin: true,
    portalShow: false,
    portalList: [],
    isregister: false,
    i18nCode: '',
    updateContract: '',
    loginShow:false,
    myaccount:false
  }),
  computed: {
    ...mapState(['modulesConfig', 'contractType', 'landInfoUpdateAt', 'isScatterConnected', 'scatterAccount', 'isScatterLoggingIn', 'balances', 'marketInfo', 'stakedInfo', 'globalInfo', 'dividendInfo', 'myCheckInStatus']),
    ...mapState('ui', ['navBurgerVisible', 'latestBuyerVisible', 'globalSpinnerVisible', 'globalProgressVisible', 'globalProgressValue']),
  },
  watch: {
    i18nCode (val) {
      this.$i18n.locale = val;
      localStorage.setItem('language', val)
    },
    updateContract (newVal, val) {
      if (val) {
        console.log(this.$route.path);
        if (this.$route.path.indexOf('map') && !this.modulesConfig[newVal].map) {
          this.$router.push('/')
        }

        Global.setGlobalContract(newVal);
        setTimeout(() => {
          this.updateContractType(newVal);
          this.updateLandInfoAsync();
          this.updateMarketInfoAsync();
          this.getGlobalInfo();
        }, 0)
      }
    }
  },
  created() {
    // this.modulesConfig[this.contractType].map && this.$router.push('/map');
    this.updateContract = this.contractType;
    this.countdownUpdater = setInterval(() => {
      if (this.globalInfo != null) {
        const currentTimestamp = Math.floor(Date.now() / 1000);
        if (currentTimestamp >= this.globalInfo.ed) {
          this.globalCountdown = 'ENDED';
        } else {
          let remaining = this.globalInfo.ed - currentTimestamp;
          const seconds = `${remaining % 60}`;
          remaining = Math.floor(remaining / 60);
          const minutes = `${remaining % 60}`;
          remaining = Math.floor(remaining / 60);
          const hours = `${remaining}`;
          this.globalCountdown = `${hours.padStart(2, '0')}:${minutes.padStart(2, '0')}:${seconds.padStart(2, '0')}`;
        }
      }
    }, 1000);

    Global.$on('onLoadMap', () => {
      console.log('loading map');
      this.appLogin = true
    });

    Global.$on('portalList', portalList => {
      this.portalList = portalList
    });

    this.getLangCode()
  },
  mounted() {
    this.connectScatterAsync();
    this.updateLandInfoAsync();
    this.updateMarketInfoAsync();
    this.getGlobalInfo();
    this.myaccount = JSON.parse(localStorage.getItem('info')).isLogin

    setInterval(() => {
      this.updateLandInfoAsync();
    }, 30 * 1000);
  },
  methods: {
    ...mapActions(['updateContractType', 'getMyStakedInfo', 'getMyBalances', 'connectScatterAsync', 'updateLandInfoAsync', 'loginScatterAsync', 'logoutScatterAsync', 'updateMarketInfoAsync', 'getGlobalInfo']),
    async vote (voteName, callback) {
      try {
        await getApi(this.contractType).api.voteAsync({
          to: voteName,
          tokenContract: this.contractType === 'eos' ? 'dacincubator' : 'ncldwqxpkgav'
        });
        this.$toast.open({
          message: '投票成功',
          type: 'is-success',
          duration: 3000,
          queue: false,
        });
        this.getMyStakedInfo();
        callback && callback()
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Stake failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
          position: 'is-bottom',
        });
      }
    },
    async stake() {
      let amount = window.prompt(this.$t('stake_number_alert'));
      amount = parseFloat(amount).toFixed(4);
      amount += ' EON';
      try {
        await getApi(this.contractType).api.stakeCMUAsync({
          from: this.scatterAccount.name,
          to: 'Dimension Meetup',
          memo: 'stake',
          tokenContract: this.contractType === 'eos' ? 'dacincubator' : 'ncldwqxpkgav',
          amount,
        });
        this.getMyStakedInfo();
        this.getGlobalInfo();
        this.getMyBalances();
        this.$dialog.alert({
          type: 'is-black',
          title: this.$t('stake_successful_alert'),
          message: this.$t('stake_pay_attention_alert'),
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Stake failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
          position: 'is-bottom',
        });
      }
    },
    async unstake() {
      try {
        const amount = parseFloat(window.prompt(this.$t('unstake_alert'))).toFixed(4) + ' EON';
        await getApi(this.contractType).api.unStakeCMUAsync({
          from: this.scatterAccount.name,
          amount,
        });
        this.getMyStakedInfo();
        this.getGlobalInfo();
        this.getMyBalances();
        this.$dialog.alert({
          type: 'is-black',
          title: this.$t('unstake_success'),
          message: this.$t('wait_alert'),
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Unstake failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
    },
    async refund() {
      try {
        await getApi(this.contractType).api.refund({
          tokenContract: this.contractType === 'eos' ? 'dacincubator' : 'ncldwqxpkgav'
        });
        this.getMyStakedInfo();
        this.getGlobalInfo();
        this.getMyBalances();
        this.$dialog.alert({
          type: 'is-black',
          message: 'Refund Success',
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Unstake failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
    },
    async claim() {
      try {
        await getApi(this.contractType).api.claim();
        this.$dialog.alert({
          type: 'is-black',
          title: this.$t('claim_success'),
          message: this.$t('wait_alert'),
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Claim failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
    },
    async buyCMU() {
      let amount = window.prompt(this.$t('buy_cmu_alert'));
      amount = parseFloat(amount).toFixed(4);
      amount += ` ${this.contractType === 'eos' ? 'EOS' : 'BOS'}`;
      try {
        await getApi(this.contractType).api.transferTokenAsync({
          from: this.scatterAccount.name,
          to: 'Dimension Meetup',
          memo: 'buy',
          amount,
        });
        this.getMyStakedInfo();
        this.getMyBalances();
        this.$dialog.alert({
          type: 'is-black',
          title: this.$t('buy_cmu_success_alert'),
          message: this.$t('after_buy_cmu_alert'),
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Buy CMU failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
    },
    async sellCMU() {
      let amount = window.prompt(this.$t('sell_cmu_alert'));
      amount = parseFloat(amount).toFixed(4);
      amount += ' EON';
      try {
        await getApi(this.contractType).api.transferTokenAsync({
          from: this.scatterAccount.name,
          to: 'Dimension Meetup',
          tokenContract: this.contractType === 'eos' ? 'dacincubator' : 'ncldwqxpkgav',
          memo: 'sell',
          amount,
        });
        this.getMyStakedInfo();
        this.getMyBalances();
        this.$dialog.alert({
          type: 'is-black',
          title: this.$t('sell_cmu_success_alert'),
          message: this.$t('after_sell_cmu_alert'),
          confirmText: this.$t('ok'),
        });
      } catch (error) {
        console.error(error);
        let msg;
        if (error.message === undefined) {
          msg = JSON.parse(error).error.details[0].message;
        } else {
          msg = error.message;
        }
        this.$toast.open({
          message: `Stake failed: ${msg}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
    },
    async startRedeem() {
      this.isRedeeming = true;
      const redeemCode = window.prompt('Please enter redeem code');
      try {
        await getApi(this.contractType).api.redeemCodeAsync({ code: redeemCode });
        this.$toast.open({
          message: 'Redeem badge successfully.',
          type: 'is-success',
          duration: 3000,
          queue: false,
        });
        this.$store.dispatch('updateMyCheckInStatus');
      } catch (e) {
        this.$toast.open({
          message: `Redeem failed: ${e.message}`,
          type: 'is-danger',
          duration: 3000,
          queue: false,
        });
      }
      this.isRedeeming = false;
    },
    CloseAboutView() {
      this.aboutShow = !this.aboutShow;
    },
    // zidingyi(type){
    //   var that = this
    //   that.isregister = type;
    // },
    CloseTokenView() {
      this.tokenShow = !this.tokenShow;
    },
    CloseMobileAboutView() {
      this.mobileAboutShow = !this.mobileAboutShow;
    },
    CloseMobileTokenView() {
      this.mobileTokenShow = !this.mobileTokenShow;
    },
    changeInviteStatus() {
      this.isInviteDialogActive = true;
    },
    // register(){
    //   var that = this
    //   that.isregister = true;
    // },
    taggleMyPortal () {
      this.portalShow = !this.portalShow
    },
    closeMyPortal () {
      this.portalShow = false
    },
    getLangCode () {
      const language = localStorage.getItem('language') || (navigator.language.toLowerCase() === 'zh-tw' ? 'zh_tw' : navigator.language.split('-')[0]);
      this.i18nCode = ['en', 'ja', 'ko', 'ru', 'zh', 'zh_tw'].includes(language) ? language : 'en'
    },
    closelogin(){
    this.loginShow = false
    this.myaccount = JSON.parse(localStorage.getItem('info')).isLogin
    console.log(this.myaccount)
  },
  logout(){
    localStorage.clear();
    this.myaccount = false
    console.log(this.myaccount)
    // console.log(123)
  }
// login1(){
//   this.loginShow = !this.loginShow
// }
  },
  beforeDestroy () {
    Global.$off('onLoadMap');
    Global.$off('portalList')
  },
  
};
</script>

<style lang="sass">
@import "~mapbox-gl/dist/mapbox-gl.css";
@import "~bulma";
@import "~buefy/src/scss/buefy";
a:hover
  text-decoration: underline
.is-inverted > .select
  & select
    background: rgba(#000, 0.7)
    border-color: transparent
    color: #FFF
    &:hover
      border-color: rgba(#FFF, 0.4)
  &:not(.is-multiple):not(.is-loading):hover::after
    border-color: #FFF
.select select option
  color: #FFF
.modal-card
  box-shadow: 0 0 30px $primary
</style>


<style lang="sass" scoped>

#app
  position: absolute
  left: 0
  top: 0
  width: 100%
  height: 100%
  overflow: hidden
.app-nav
  position: absolute
  left: 2rem
  top: 2rem
  z-index: 1
  display: flex
  flex-direction: row
  justify-content: flex-start
.nav-item
  margin-right: 120px
  margin-top: 3px
  color: rgba(#FFF, 0.8)
  user-select: none
  text-shadow: 1px 1px 2px rgba(#000, 0.5)
  font-size: 16px
  padding: 3px 0;
  > div
    &:hover
      border-bottom: 1px solid #0D6FDF
  &:hover
    color: #0D6FDF
    text-decoration: none

  &.router-link-exact-active
    color: rgba(255, 255, 255, 0.8)
.app-footer
  position: absolute
  left: 2rem
  right: 2rem
  bottom: 2rem
  z-index: 1
  display: flex
  flex-direction: row
  justify-content: center
  align-items: center
  text-shadow: 1px 1px 2px rgba(#000, 0.5)
  a:hover
    text-decoration: none
.footer-item
  margin: 0 0.5rem
  font-size: $size-7
.app-nav-burger
  position: relative
  left: 0
  top: 0
  z-index: 5
  color: #FFF
  +hamburger($app-nav-height)
  cursor:auto
  a
    display: block
    color: #FFF
    width: 3rem
    height: 3rem
    cursor: pointer
.app-nav-expand
  position: absolute
  right: 0
  top: 0
  width: 100%
  height: 100%
  z-index: 4
  background: rgba(#000, 0.9)
  padding-top: $app-nav-height
  &-item
    display: block
    width: 100%
    padding: 1rem
    border-top: 1px solid rgba(#FFF, 0.2)
    color: #FFF
    font-size: $size-7
    &:hover
      text-decoration: none
      background: rgba(#FFF, 0.1)
.country-detail
  position: absolute
  right: 0 !important
  top: 0
  height: 100%
  z-index: 2
  pointer-events: none
  transition: background .5s ease-out
  width: 550px
  display: flex
  flex-direction: column
  &.is-active
    pointer-events: auto
    background: rgba(#000, 0.8)
  +mobile
    width: 100%
.mobile-back-button
  width: $app-nav-height
  height: $app-nav-height
  margin: 0
  display: flex
  justify-content: center
  align-items: center
.country-select
  +mobile
    margin: 0 0.5rem 0 0
    width: calc(100vw - #{$app-nav-height} - 0.5rem)
  .back-button
     position: absolute !important
     top: 2px  !important
     left: 10px  !important
.badgeList
  margin: 1rem 0
.app-map-login
    position: absolute
    left: 5rem
    top: .6rem
</style>
<style>

.login{
  border: 1px solid rgba(255, 255, 255, 0.8);
  padding: 3px 10px!important;
}
.login:hover{
  border-color: #0D6FDF;
}
 .select select{
  color: rgba(255, 255, 255, 0.8) !important;
  border: none;
  background-color: rgba(255, 255, 255, 0) !important;
  font-size: 16px;
}
.select select option{
  background: #000;
  color:  rgba(255, 255, 255, 0.8);
}
 .select select:hover{
   color: #0D6FDF;
  background-color: rgba(255, 255, 255, 0);
   
 }
.select:not(.is-multiple):not(.is-loading)::after {
    border-color: rgba(255, 255, 255, 0.8);
}
.select select option{
    border-color: rgba(255, 255, 255, 0.8);
}
.globe-control-item .select{
  border: 1px solid rgba(255, 255, 255, 0.8) !important;
}
.element::-webkit-scrollbar {display:none}
.button.is-white.is-outlined {
    background-color: transparent;
    border-color: white;
    color: white;
    position: absolute;
    left: 20px;
    border-radius: 0px;
    height: 36px;
    font-size: 16px;
    width: 100px;
}
.blue{
  color: #5AC8FA !important;
}
.button{
  background-color: #5AC8FA;
  border: none;
  width: 100%;
  height: 50px;
}
.button a{
  color: #fff
}
.loginView{
  padding: 120px 50px;
  width: 550px;
  position: absolute;
  right: 0;
  height: 100%;
  background-color: rgba(0,0,0,0.8);
  z-index: 99
}
.el-form-item__content{
  margin-left: 0px;
}
.el-input__inner{
  background-color: #000;
  border-color: #787878;
  color: #5F5F5F;
}
.el-form-item.is-error .el-input__inner{
  border-color: #D0021B
}
.el-form-item__error{
  color: #D0021B
}
.el-form-item {
    margin-bottom: 30px;
}
.el-button--primary {
    color: #FFF;
    background:linear-gradient(118deg,rgba(90,200,250,1) 0%,rgba(0,192,210,1) 100%);
    border-color: #409EFF;
    border-radius:6px
}
.code .el-input {
  width: 60%;
}
.code .el-form-item__content{
  display: flex;
  width: 100%;
}
.el-input{
  width: 100%;
}
.el-form-item.is-error .el-input__inner{
  color: #fff
}
.el-form-item.is-error .el-input__inner, .el-form-item.is-error .el-input__inner:focus, .el-form-item.is-error .el-textarea__inner, .el-form-item.is-error .el-textarea__inner:focus, .el-message-box__input input.invalid, .el-message-box__input input.invalid:focus{
  border-color: #D0021B
}
.el-icon-refresh-right{
      font-size: 30px;
    line-height: 40px;
  font-weight: 400;
  cursor: pointer;
}
.button.is-white.is-outlined{
  left: -67px;
}
.errorMess{
      font-size: 12px;
    color: #D0021B;

    line-height: 23px;
}
.code img{
      margin: 0 10px;
      height: 40px;
}
</style>