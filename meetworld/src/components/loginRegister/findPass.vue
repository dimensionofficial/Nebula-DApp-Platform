<template>
<div>
  <div class="first" v-show="first">
    <h1>{{$t('findPass')}}</h1>

        <div class="passLogin" v-show="passLogin">
      <el-form :model="ruleForm" status-icon :rules="rules" ref="ruleForm" >

      <el-form-item  prop="email">
        <el-input type="e-mail" v-model="ruleForm.email"  :placeholder="$t('inputEmail')"></el-input>
      </el-form-item>

     <el-form-item  prop="imgCode">
       <div class="code">
          <el-input type="text" v-model="ruleForm.imgCode" @blur="_checkImgCode()" :placeholder="$t('inputCode')"> </el-input><img :src="imgCodeSrc" alt=""><i @click="refresh()" class="el-icon-refresh-right"></i>
       </div>
       
        <p class="errorMess">{{imgText}}</p>
      </el-form-item>
      

      <el-form-item   prop="emailCode">
        <div class="code">
          <el-input class="code" type="text" v-model="ruleForm.emailCode"  :placeholder="$t('inputCode')"> </el-input>
        <div :class="{'get-code-btn':true, 'disabled': isDisabledBtn}"
                 @click="getActiveCodeFunc()">
              {{getBtnText}}
            </div>
        </div>
        <p class="errorMess">{{emailText}}</p>
      </el-form-item>
      



      <el-form-item>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="submitForm('ruleForm')">{{$t('resetPass')}}</el-button>
      </el-form-item>
    </el-form>
    </div>

  </div>
    <div class="second" v-show="second">
      <h1>{{$t('resetPass')}}</h1>

        <el-form :model="ruleForm1" status-icon :rules="rules1" ref="ruleForm1">
        <el-form-item  prop="pass">
        <el-input type="password" v-model="ruleForm1.pass"  :placeholder="$t('passRule')"></el-input>
      </el-form-item>

        <el-form-item  prop="checkPass">
            <el-input type="password" v-model="ruleForm1.checkPass"  :placeholder="$t('checkPass')"></el-input>
        </el-form-item>
        <el-form-item>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="submitForm1('ruleForm1')">{{$t('stake_confirmed_btn')}}</el-button>
      </el-form-item>
        </el-form>
      </div>
    <div class="third" v-show="third">
  <h1>{{$t('resetPass')}}</h1>
<p>{{$t('changePass')}}</p>
<a  @click="finish()">{{$t('loginNow')}}</a>
    </div>
</div>
</template>

<script>
import {getImgCode,checkImgCode,checkUser,getNumCode,checkNumCode,changePass} from '@/api/api'

  export default {
    data() {
      var validateEmail = (rule, value, callback) => {
        if (value === '') {
          callback(new Error($t('inputEmail')));
        } else {
          if (this.ruleForm.email !== '') {
            this.$refs.ruleForm.validateField('email');
          }
          callback();
        }
      };
    var validatePass2 = (rule, value, callback) => {
        if (value === '') {
          callback(new Error($t('checkPass')));
        } else if (value !== this.ruleForm1.pass) {
          callback(new Error($t('checkPasswrong')));
        } else {
          callback();
        }
      };
      var validatePass = (rule, value, callback) => {
        if (value === '') {
          callback(new Error($t('pass')));
        } else {
          if (this.ruleForm.checkPass !== '') {
            this.$refs.ruleForm.validateField('checkPass');
          }
          callback();
        }
      };

      return {
        ruleForm: {
          email: '',
          imgCode:'',
          emailCode:'',
        },
        ruleForm1: {
            pass:'',
            checkPass:''
        },
        imgText:'',
        emailText:'',
        imgCodeSrc:'',
        first:true,
        second:false,
        false:false,
        passLogin:true,
        getBtnText: this.$t('sendCode'),
        isDisabledBtn: false,
        rules: {
          
          imgCode: [
            {  required: true, message: this.$t('inputCode'), trigger: 'blur'  },
          ],
          email: [
            {  required: true, message: this.$t('inputEmail'), trigger: 'blur'  },
            { type: 'email', message: this.$t('inputCorrentEmail'), trigger: ['blur', 'change'] }
          ],

          emailCode:[
              {required: true, message: this.$t('inputEmailCode'), trigger: 'blur' }
          ]

        },
        rules1: {

          pass: [
            { validator: validatePass, trigger: 'blur' },
              { pattern: /[A-z0-9]{8,16}/, message: this.$t('passRule') }

     

          ],
          checkPass: [
            { validator: validatePass2, trigger: 'blur' },
              { pattern: /[A-z0-9]{8,16}/, message: this.$t('passRule') }


          ],


        }

      };
    },
    methods: {
      submitForm(formName) {
        this.$refs[formName].validate((valid) => {
          if (valid) {
            // alert('submit!');

        var that = this
        checkNumCode({
              name:that.ruleForm.email,
              code:that.ruleForm.emailCode,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
                if(res.data.code == 500){
                  that.emailText = that.$t('wrongNumCode')
                }else{
                  that.emailText = ""
                  that.first = false
                  that.second = true
                }
              console.log(res)
            }).catch(error => {
              console.log(error)
            })
            // that.codeFocus=false

            
          } else {
            console.log('error submit!!');
            return false;
          }
        });
      },
      submitForm1(formName) {
        this.$refs[formName].validate((valid) => {
          if (valid) {
            // alert('submit!');
            

          var that = this
        changePass({
              // code:that.$store.state.findPassInfo.code,
              name:that.ruleForm.email,
              password:that.ruleForm1.pass,
              
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
                if(res.data.code == 200){
                  that.$toast(that.$t('resetS'));
                  that.second = false
                  that.third = true
                }else{
                  that.$toast(that.$t('resetF'));
                }
              console.log(res)
            }).catch(error => {
              console.log(error)
            })
          } else {
            console.log('error submit!!');
            return false;
          }
        });
      },
      finish(){

          this.$emit('goLogin');
      },
      passLogin(){
        this.passLogin = true
      },
      codeLogin(){
        this.passLogin = false
      },
       getActiveCodeFunc() {

        var that = this
         let time = 60;
                  that.isDisabledBtn = true;
                  // let that = this;
                  that.getBtnText = that.$t('reSend')+` (${time}s)`;
                  
                  let timer = setInterval(function () {
                    time -= 1;
                    that.getBtnText = that.$t('reSend')+` (${time}s)`;
                    if(time <= 0) {
                      clearInterval(timer);
                      that.isDisabledBtn = false;
                      that.getBtnText = that.$t('sendCode');
                    }
                  }, 1000)
            getNumCode({
              name:that.ruleForm.email,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){

                 
              console.log(res)
            }).catch(error => {
              console.log(error)
            })
       

      },
            // 验证图片验证码
      _checkImgCode(){
        var that = this
        checkImgCode({
              code:that.ruleForm.imgCode,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
               if(res.data.code == 500){
                  that.imgText = that.$t('wrongImgCode')
                }else{
                  that.imgText = ""
                }
            }).catch(error => {
              console.log(error)
            })
            that.codeFocus=false
      },
      
      // 图片验证码重置
      refresh(){
        var that = this;
        console.log(JSON.parse(localStorage.getItem('token')).token)
        getImgCode({
        token:JSON.parse(localStorage.getItem('token')).token
        }).then(function(res){
          console.log(res)
        that.imgCodeSrc = res.data
        }).catch(error => {
        console.log(error)
        })
      },
    },
    mounted() {
// 获取验证码
       var that = this;
      console.log(JSON.parse(localStorage.getItem('token')).token)
      getImgCode({
        token:JSON.parse(localStorage.getItem('token')).token
        }).then(function(res){
          console.log(res)
        that.imgCodeSrc = res.data
      }).catch(error => {
        console.log(error)
      })
    }
  }
</script>
<style scoped>
  h1{
    font-size: 30px;
    color: #5AC8FA;
  }
  input{
    background-color: #000;
    border: 1px solid #00EAFF;
    width: 100%;
    height: 40px;
    line-height: 40px;
    padding: 0 14px;
    color: #fff
  }
  .kuang{
    margin-bottom: 30px;
  }
  h1{
    margin-bottom: 30px;
  }
  /* .login{
    background-color: #D2D2D2;
    height: 45px;
    width: 100%;
    color: #fff;
  }  */
  .submit{
    width: 100%;
    height: 45px;
  }
  .bottom{
    position: absolute;
    bottom: 80px;
    width: 100%;
    color: #00EAFF;
    font-size: 12px;
  }
  .bottom .right{
    position: absolute;
    right: 110px;
  }
  .tu{
    background-color: #ccc;
    height: 40px;
    line-height: 40px;
    width: 25%;
    display: inline-block;
    margin-left: 10%;
    text-align: center;
  }
  .user{
      text-align: center;
      font-size: 12px;
  }
  .user span{
      color: #00EAFF
  }
  .help{
      font-size: 12px;
      margin: 0;
          height: 20px;
    line-height: 20px;
  }
  .second p{
      font-size: 18px;
        line-height: 30px;
        margin-bottom: 20px;
  }
  .second  .user{
      text-align: center;
      font-size: 12px;
  }
  .second .user span{
      color: #00EAFF
  }

    .get-code-btn {
    /*right: -140px;*/
    width: 35%;
    margin-left: 2%;
    color: #fff;
    font-size: 12px;
    font-weight:400;

    line-height: 40px;
    text-align: center;
background:linear-gradient(118deg,rgba(90,200,250,1) 0%,rgba(0,192,210,1) 100%);
border-radius:3px;
border:1px solid rgba(151,151,151,1);
    cursor: pointer;
    outline: none;
        display: inline-block;
        height: 40px;
  }
  .get-code-btn.disabled {
    pointer-events: none;
    background: rgba(226,226,226,1);;
    border-color: #ebebeb;
    /*color: #ebebeb;*/
  }
  .code{
      display: flex;
      width: 100%;
  }
  .second button{
      margin: 20px 0;
  }
</style>
