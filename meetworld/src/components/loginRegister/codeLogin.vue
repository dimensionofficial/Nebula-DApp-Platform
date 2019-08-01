<template>
<div>
    
  <h1>{{$t('welcome')}}</h1>
  <div class="codeLogin" >
    <el-form :model="ruleForm" status-icon :rules="rules" ref="ruleForm" >

      <el-form-item  prop="tel">
        <el-input type="text" v-model="ruleForm.tel"  :placeholder="$t('inputTel')"></el-input>
      </el-form-item>

      <el-form-item  prop="img">
        <div class="code">
          <el-input type="text" v-model="ruleForm.img" @blur="_checkImgCode()"  :placeholder="$t('inputCode')"> </el-input><img :src="imgCodeSrc" alt=""><i @click="refresh()" class="el-icon-refresh-right"></i>
        </div>
        <p class="errorMess">{{imgText}}</p>
        
      </el-form-item>
      
      <el-form-item  prop="email">
        <div class="code">
          <el-input type="text" v-model="ruleForm.emailCode"  :placeholder="$t('inputEmailCode')"></el-input><div :class="{'get-code-btn':true, 'disabled': isDisabledBtn}"
                 @click="getActiveCodeFunc()">
              {{getBtnText}}
            </div>

        </div>
        <p class="errorMess">{{emailText}}</p>
        
      </el-form-item>

      <el-form-item>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="submitForm('ruleForm')">{{$t('login')}}</el-button>
      </el-form-item>
    </el-form>
  </div>


</div>
</template>

<script>
import {getImgCode,checkImgCode,checkUser,getNumCode,checkNumCode,changePass} from '@/api/api'


  export default {
    data() {


      return {
        ruleForm: {
          tel: '',
          emailCode: '',
          img:'',
          login: 'false'
        },
        imgText:'',
        emailText:'',
        imgCodeSrc:'',
        rules: {
          img: [
            {  required: true, message: this.$t('inputCode'), trigger: 'blur'  },
          ],
          emailCode: [
            {  required: true, message: this.$t('inputEmailCode'), trigger: 'blur'  },
          ],
          tel: [
            {  required: true, message: this.$t('inputTel'), trigger: 'blur'  },
          ],

        },
         getBtnText: this.$t('sendCode'),
        isDisabledBtn: false,
      };
    },
    methods: {
      submitForm(formName) {
        
        this.$refs[formName].validate((valid) => {
          var that = this
          if (valid) {
            // alert('submit!');
            checkNumCode({
              name:that.ruleForm.tel,
              code:that.ruleForm.emailCode,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
                if(res.data.code == 500){
                  that.emailText = that.$t('wrongNumCode')
                }else{
                  that.emailText = ""
                  console.log(123)
                   const info = { isLogin:true,name:that.ruleForm.email };
                  localStorage.setItem('info', JSON.stringify(info));
                  that.$toast(that.$t('loginS'));
          that.$emit('closeclose');
                  
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
              name:that.ruleForm.tel,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){

                 
              console.log(res)
            }).catch(error => {
              console.log(error)
            })
      },
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
      _checkImgCode(){
        var that = this
        checkImgCode({
              code:that.ruleForm.img,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
               if(res.data.code == 500){
                  that.imgText = that.$t('wrongImgCode')
                  console.log(res)
                }else{
                  that.imgText = ""
                }
            }).catch(error => {
              console.log(error)
            })
            that.codeFocus=false
      },
    },
    mounted() {
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
</style>
