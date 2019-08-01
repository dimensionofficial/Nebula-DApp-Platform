<template>
<div>
  <h1>{{$t('welcome')}}</h1>
  <div class="first" v-show="first">
        <div class="passLogin" v-show="passLogin">
      <el-form :model="ruleForm" status-icon :rules="rules" ref="ruleForm" >

      <el-form-item  prop="email">
        <el-input type="e-mail" v-model="ruleForm.email"  :placeholder="$t('inputEmail')"></el-input>
      </el-form-item>

    <el-form-item  prop="account">
        <el-input  v-model="ruleForm.account"  @blur="getOwnerKey()"  :placeholder="$t('inputAccount')"></el-input>
        <p class="help">{{$t('accountRule')}}</p>
      </el-form-item>

     <el-form-item  prop="imgCode">
       <div class="code">
        <el-input type="text" v-model="ruleForm.imgCode" @blur="_checkImgCode()" :placeholder="$t('inputCode')"> </el-input><img :src="imgCodeSrc" alt=""><i @click="refresh()" class="el-icon-refresh-right"></i>

       </div>
        <p class="errorMess">{{imgText}}< /p>

      </el-form-item>

      <el-form-item  prop="pass">
        <el-input type="password" v-model="ruleForm.pass"  :placeholder="$t('passRule')"></el-input>
      </el-form-item>

        <el-form-item  prop="checkPass">
            <el-input type="password" v-model="ruleForm.checkPass"  :placeholder="$t('checkPass')"></el-input>
        </el-form-item>

      <el-form-item>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="submitForm('ruleForm')">{{$t('next')}}</el-button>
      </el-form-item>
    </el-form>
  </div>
    <p class="user">{{$t('statement')}}<span>{{$t('agreement')}}</span></p>
  </div>
    <div class="second" v-show="!first">
        <p>{{$t('dear')}}{{ruleForm.email}}<br>{{$t('finishRegister')}}</p>
        <div class="code">
            <el-input class="code" type="text" v-model="emailCode"  :placeholder="$t('inputCode')"> </el-input>
        <div :class="{'get-code-btn':true, 'disabled': isDisabledBtn}"
                 @click="getActiveCodeFunc()">
              {{getBtnText}}
            </div>
        </div>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="finish()">{{$t('finish')}}</el-button>
        <p class="user">{{$t('statement')}}<span>{{$t('agreement')}}</span></p>
    </div>
</div>
</template>

<script>
import {getImgCode,checkImgCode,addUser,activateUser,checkUser,getNumCode} from '@/api/api'

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
          callback(new Error(this.$t('checkPass')));
        } else if (value !== this.ruleForm.pass) {
          callback(new Error(this.$t('checkPasswrong')));
        } else {
          callback();
        }
      };
      var validatePass = (rule, value, callback) => {
        if (value === '') {
          callback(new Error(this.$t('pass')));
        } else {
          if (this.ruleForm.checkPass !== '') {
            this.$refs.ruleForm.validateField('checkPass');
          }
          callback();
        }
      };

      return {
        ruleForm: {
          pass: '',
          email: '',
          login: 'false',
          checkPass:'',
          account: '',
          imgCode:''
        },
        emailCode:'',
        imgCodeSrc:'',
        imgText:'',
        publicKeyInput: "",
        privateKeyInput: "",
        first:true,
        passLogin:true,
        getBtnText: this.$t('sendCode'),
        isDisabledBtn: false,
        rules: {
          pass: [
            { validator: validatePass, trigger: 'blur' },
              { pattern: /[A-z0-9]{8,16}/, message: this.$t('passRule') }

            // { pattern: /[a-Z0-9]{8, 16}/, message: this.$t('passRule') }
          ],
          imgCode: [
            {  required: true, message: this.$t('inputCode'), trigger: 'blur'  },
          ],
          email: [
            {  required: true, message: this.$t('inputEmail'), trigger: 'blur'  },
            
            { type: 'email', message: this.$t('inputCorrentEmail'), trigger: ['blur', 'change'] },
              

          ],
          checkPass: [
            { validator: validatePass2, trigger: 'blur' },
              { pattern: /[A-z0-9]{8,16}/, message: this.$t('passRule') }

          ],
          account:[
              {required: true, message: this.$t('inputAccount'), trigger: 'blur' },
              { pattern: /^[a-z1-5][a-z1-5.]{4,10}[a-z1-5]$/, message: this.$t('inputAccount') }
          ]

        },

      };
    },
    methods: {
      submitForm(formName) {
        this.$refs[formName].validate((valid) => {
          if (valid) {
            // alert('submit!');
            var that = this
            addUser({
              name:that.ruleForm.email,
              password:that.ruleForm.pass,
              address:that.ruleForm.account,
              pubkey:that.publicKeyInput,
              prikey:that.privateKeyInput,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
                // 激活码
                if(res.data.code == 200){
                  console.log(res)
                  // getNumCode({
                  //   name:that.ruleForm.email,
                  //   token:JSON.parse(localStorage.getItem('token')).token
                  //   }).then(function(res){
                  //     that.first = false
                      
                  //   console.log(res)
                  // }).catch(error => {
                  //   console.log(error)
                  // })
                  // that.$router.push({path: '/active',query:{name:that.validateFormRegister.username}});
                      that.first = false
                  
                }else{
                that.$toast(that.$t('registerF'));
                  // console.log(123)
                }
                


            }).catch(error => {
              console.log(error)
            })
            
          } else {
            console.log('error submit!!');
                that.$toast(that.$t('registerF'));

            return false;
          }
        });
      },
       refresh(){
        var that = this
          getImgCode({token:JSON.parse(localStorage.getItem('token')).token}).then(function(res){
            console.log(res)
          that.imgCodeSrc = res.data
        }).catch(error => {
          console.log(error)
        })
      },
      finish(){
        var that =this
        console.log(that.value)
        activateUser({
            name:that.ruleForm.email,
            code:that.emailCode,
            token:JSON.parse(localStorage.getItem('token')).token
            }).then(function(res){
                    console.log(res.data)
                    console.log(res)
            if(res.data.code == 200){
                that.$toast(that.$t('activeS'));
                that.$emit('goLogin');
            // that.$router.push({ path: '/login'})

            }else{
                that.$toast(that.$t('activeF'));

            }
            
        }).catch(error => {
            console.log(error)
        })
          
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
      getOwnerKey() {
        let _this = this;
        if(!this.ruleForm.account) {
          return false;
        }
        getWebSocketKey();

        //初始化websocket接口，获取公钥私钥对
        function getWebSocketKey() {
          // ws地址
          _this.keysWebSocket = new WebSocket(
            "ws://" + '13.125.66.151:8081' + "/createKey"
          );
          _this.keysWebSocket.onmessage = webSocketOnmessage;
          _this.keysWebSocket.onclose = webSocketClose;
          _this.keysWebSocket.onopen = webSocketSend;
        }

        function webSocketOnmessage(e) {
          // 数据接收
          let reg = RegExp(/\{/);
          if (reg.test(e.data)) {
            let newData = "{" + e.data.split("{")[1].split("}")[0] + "}";
            newData = JSON.parse(newData);
            if (newData["type"] === "create_key") {
              _this.publicKeyInput = newData["Public_key"];
              _this.privateKeyInput = newData["Private_key"];
              // console.log(_this.publicKeyInput)
              //关闭websocket接口
              webSocketClose();
            }
          }
        }
        function webSocketSend() {
          // 连接建立之后，数据发送
          //将用户名转成json字符串发送给后台
          let message = JSON.stringify({
            username: _this.ruleForm.account
          });
          _this.keysWebSocket.send(message);
        }

        function webSocketClose() {
          // 关闭
          _this.keysWebSocket.close();
          // _this.keysWebSocket = null;
        }
        _this
          .$axios({
            method: "post",
            url: "http://" + '13.125.66.151:8081' + "/user/key",
            headers: {
              "Content-Type": "application/json"
            }
          })
          .then(function (res) {
          })
          .catch(function (error) {
            console.log(error);
          });
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
