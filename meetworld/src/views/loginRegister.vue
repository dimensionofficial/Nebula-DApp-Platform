<template>
  <div>
    <i @click="close()" class="el-icon-close"></i>
    <pass-login @closeclose="close()" v-if="passLogin" />
    <code-login @closeclose="close()" v-if="codeLogin" />
    <register @goLogin="passlogin()" v-if="isregister" />
    <find-pass @goLogin="passlogin()" v-if="isfindpass" />
    <p v-if="isfindpass" class="bottom findpass">
      <a @click="passlogin()">{{$t('login')}}</a>&nbsp;|&nbsp;
      <a @click="register()">{{$t('register')}}</a>
    </p>
    <p v-show="!isfindpass" class="bottom">
      <a @click="codelogin()" v-if="!codeLogin">{{$t('codeLogin')}}</a>
      <span v-if="isregister">&nbsp;|&nbsp;</span>
      <a @click="passlogin()" v-if="!passLogin">{{$t('passLogin')}}</a>
      <span v-if="!isregister">&nbsp;|&nbsp;</span>
      <a v-if="!isregister" @click="register()">{{$t('registerAccount')}}</a>
      <a class="right" @click="findpass()">{{$t('forgetPass')}}</a>
    </p>
  </div>
</template>

<script>
import { index} from '@/api/api'

import passLogin from "@/components/loginRegister/passLogin.vue";
import codeLogin from "@/components/loginRegister/codeLogin.vue";
import register from "@/components/loginRegister/register.vue";
import findPass from "@/components/loginRegister/findPass.vue";
import { close } from 'fs';
export default {
  components: {
    passLogin,
    codeLogin,
    register,
    findPass
  },
  data() {
    return {
      passLogin: true,
      codeLogin: false,
      isregister: false,
      isfindpass: false
    };
  },
  methods: {
    passlogin() {
      this.passLogin = true;
      this.codeLogin = false;
      this.isregister = false;
      this.isfindpass = false;
    },
    codelogin() {
      this.passLogin = false;
      this.codeLogin = true;
      this.isregister = false;
      this.isfindpass = false;
    },
    register() {
      this.passLogin = false;
      this.codeLogin = false;
      this.isregister = true;
      this.isfindpass = false;
    },
    close() {
      this.$emit("goclose");
    },
    close1(){
      console.log(123)
      // this.$emit("goclose");

    },
    findpass() {
      this.passLogin = false;
      this.codeLogin = false;
      this.isregister = false;
      this.isfindpass = true;
    }
  },
  mounted () {
        index({
              }).then(function(res){
                  console.log(res)
                  const token = { token:res.data.data };
                  localStorage.setItem('token', JSON.stringify(token));
                  console.log(JSON.parse(localStorage.getItem('token')).token)
            }).catch(error => {
              console.log(error)
            })
    },
};
</script>
<style scoped>
.bottom {
  position: absolute;
  bottom: 80px;
  width: 100%;
  color: #00eaff;
  font-size: 12px;
}
.bottom .right {
  position: absolute;
  right: 110px;
}
.el-icon-close {
  font-size: 40px;
  font-weight: 1000;
  position: absolute;
  right: 50px;
  top: 50px;
  cursor: pointer;
}
.findpass {
  text-align: center;
  width: 450px;
}
</style>
