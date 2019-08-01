<template>
  <div>
    <div v-if="!isCompleted">
      <div class="register-content">
        <p class="register-welcome">欢迎加入我们！</p>
        <div class="register-content-form">
          <p class="register-is-completing">尊敬的
            <span style="color: #1F2659;">{{registerInfo.username}}</span>
            ，请进行最后的验证来完成注册！</p>
          <div class="form-group register-verification-code">
            <input type="text" class="form-control text-code"
                   placeholder="请输入短信验证码"
                   v-model="numCode"
                   :class="{errorTip: errorTxtCode}"
                   @blur="checkNumCodeFormat(numCode)">
            <button type="button" class="btn btn-primary text-code-btn"
                    @click="getNumCode(registerInfo.username)"
                    :class="{sending: isSend}"
                    :disabled="isSend">{{btnTxt}}
            </button>
          </div>
          <small :class="{sendTip: isSend && errorTxtCode === '验证码已发送，请查收！'}" class="error-tip" v-if="errorTxtCode">
            {{errorTxtCode}}
          </small>
          <button type="button" class="btn btn-primary btn-block" @click="registerCompleted()">完成</button>

        </div>
      </div>
      <div class="register-footer-bar">
        <div class="register-footer-left">
          <router-link class="pass-login-btn" :to="{name: 'login'}">密码登录</router-link>
          <router-link
            :to="{name: 'codeLogin'}"
            class="verification-code verification-code-exchange"
          >验证码快捷登录
          </router-link>
        </div>
        <router-link :to="{name: 'findPass'}" class="pass-footer-forget-pass">忘记密码？</router-link>
      </div>
    </div>
    <div v-if="isCompleted" class="register-completed">
      <p class="register-success-words">恭喜您注册成功！</p>
      <p class="login-right-now">马上登录吧！</p>
      <div class="register-completed-btn">
        <div class="cancel-login-btn" @click="close()">取消</div>
        <div class="do-login-btn" @click="closeToLogin()">登录</div>
      </div>
    </div>

  </div>
</template>
<script>
  export default {
    props: [
      'registerInfo',
    ],
    data() {
      return {
        errorTxtCode: '',
        btnTxt: '获取验证码',
        isSend: false,
        numCode: '',
        isCNumCode: false,
        registerSocket: null,
        isCompleted: false,//注册是否完成
        regTimers: null,
      }
    },
    methods: {
      checkNumCodeFormat(code) {
        if (code) {
          return false;
        } else {
          this.errorTxtCode = '验证码不能为空';
        }
      },
      /*提交后台校验短信验证码，并修改input样式*/
      checkNumCode(code, name) {
        let _this = this;
        this.$axios({
          method: 'post',
          url: 'http://' + _this.baseApi + '/user/check/code',
          data: {
            "code": code,
            "username": name
          },
          headers: {
            "Content-Type": 'application/json'
          }
        }).then(function (res) {
          //console.log(res);
          if (res.data.status === 200) {
            _this.isCNumCode = true;
            _this.errorTxtCode = '';
          } else {
            _this.errorTxtCode = '验证码错误！';
            // _this.isSend = false;
          }
        }).catch(function (error) {
          console.log('短信验证码校验失败' + error);
        });
      },
      /*获取短信验证码*/
      getNumCode(name) {
        let that = this;
        //更改获取验证码按钮的状态以及样式
        let time = 59;
        that.isSend = true;
        let set = setInterval(function () {
          time--;
          that.btnTxt = time + '秒后重新发送';
          if (time === 0) {
            that.btnTxt = "获取验证码";
            that.isSend = false;
            clearInterval(set);
          }
        }, 1000);
        this.$axios({
          method: 'post',
          url: 'http://' + that.baseApi + '/user/message/send',
          data: {
            "username": name
          },
          headers: {
            "Content-Type": 'application/json'
          }
        }).then(res => {
          that.errorTxtCode = '验证码已发送，请查收！';
        }).catch(error => {
          console.log(error)
        });
      },
      /*注册完成*/
      registerCompleted() {
        let _this = this;
        this.checkNumCode(this.numCode, this.registerInfo.username);
        let options = {
          fullscreen: true,
          text: "正在注册……"
        };
        //加载提示
        let loadingInstance;

        initWebSocketRegister();

        let regTimer = setInterval(function () {
          if (_this.isCNumCode) {
            loadingInstance = _this.$loading(options);
            getRegister();
            clearInterval(regTimer);
          }
        }, 50);

        /*初始化创建钱包socket*/
        function initWebSocketRegister() {
          _this.registerSocket = new WebSocket('ws://' + _this.baseApi + '/wallet');
          _this.registerSocket.onmessage = registerSocketMessage;
          //打开链接
          _this.registerSocket.onopen = function () {
            //将用户名转成json字符串发送给后台
            let message = JSON.stringify({
              "username": _this.registerInfo.name
            });
            _this.registerSocket.send(message);
          };
          //关闭连接
          _this.registerSocket.onclose = registerSocketClose;

          _this.registerSocket.onerror = function (ev) {
            //关闭进度条
            loadingInstance.close();
            //提示用户，购物成功
            _this.$message({
              message: '注册失败！',
              type: 'warning'
            });
          }
        }

        //接收信息
        function registerSocketMessage(e) {
          if (e.data === _this.registerInfo.name) {
            clearTimeout(_this.regTimers);
            //关闭进度条
            loadingInstance.close();
            //提示用户，注册成功
            _this.$message({
              message: '注册成功',
              type: 'success'
            });
            //跳转到完成注册页面
            _this.isCompleted = true;
            registerSocketClose();
          }
        }

        //关闭连接
        function registerSocketClose(e) {
          _this.registerSocket.close();
        }

        function getRegister() {
          _this.$axios({
            method: 'post',
            url: 'http://' + _this.baseApi + '/user/register',
            data: {
              ..._this.registerInfo,
              "code": _this.numCode,
            },
            headers: {
              "Content-Type": 'application/json'
            }
          }).then(function (res) {
          }).catch(function (error) {
          });
          _this.regTimers = setTimeout(function () {
            //关闭进度条
            loadingInstance.close();
            //提示用户，购物成功
            _this.$message({
              message: '注册失败,请重新尝试注册！',
              type: 'error'
            });
            clearTimeout(_this.regTimers);
          }, 30000);
        }
      },
      close() {
        this.isCompleted = false;
        this.$router.push({
          name: 'IndexPage'
        });
      },
      closeToLogin() {
        this.isCompleted = false;
        this.$router.push({
          name: 'login'
        });
      },
    }
  }
</script>
<style>
  a:hover {
    text-decoration: none;
  }

  /*错误提示样式*/
  .error-tip {
    display: block;
    font-size: 14px;
    color: #d0021b;
  }

  .errorTip {
    border: 1px solid #d0021b;
  }

  .register-welcome,
  .generate-welcome {
    font-size: 24px;
    color: #4e537b;
  }

  .register-is-completing {
    margin-top: 50px;
    font-size: 22px;
    color: #c1becb;
  }

  .register-footer-bar {
    display: flex;
    justify-content: space-between;
    font-size: 14px;
    color: #4e537b;
  }

  .register-footer-bar .register-footer-left {
    display: flex;
  }

  .register-footer-left a {
    margin-right: 5px;
  }

  .register-footer-bar a:hover {
    color: #4e537b;
    text-decoration: none;
  }

  .pass-login-btn::after {
    content: " | ";
  }

  .register-verification-code {
    display: flex;
    justify-content: space-between;
  }

  .register-verification-code .text-code {
    width: 220px;
  }

  .register-verification-code button.text-code-btn {
    margin-top: 15px;
    height: 42px;
    width: 120px;
    background: #5c5cf9;
    border-radius: 4px;
    border: none;
    font-size: 14px;
    color: #ffffff;
    text-align: center;
  }

  .register-verification-code input:focus {
    background: #ffffff;
    border: 1px solid #6655ff;
    box-shadow: 2px -2px 15px 0 rgba(3, 8, 50, 0.06);
    border-radius: 4px;
  }

  .btn-primary:focus {
    box-shadow: none;
  }

  input::placeholder {
    font-size: 14px;
    color: #c1becb;
  }

  button.btn {
    background-image: linear-gradient(-90deg, #5577ff 4%, #6633ee 97%);
    border-radius: 8px;
    height: 48px;
    margin-top: 20px;
    font-size: 18px;
    color: #ffffff;
    text-align: center;
  }

  .form-group input.form-control {
    height: 42px;
    margin-top: 15px;
  }

  .sending {
    background-color: #C1BECB !important;
  }

  .sendTip {
    color: #417505;
  }

  .register-success-words {
    font-size: 24px;
    color: #4e537b;
    text-align: center;
    margin-top: 50px;
  }

  .register-completed-btn {
    display: flex;
    margin-top: 60px;
    width: 100%;
    height: 64px;
    font-size: 18px;
    /*color: #C1BECB;*/
    text-align: center;
    line-height: 64px;
    border-top: 1px solid #f0f4fa;
    box-sizing: border-box;
  }

  .register-completed-btn .cancel-login-btn {
    width: 50%;
    color: #c1becb;
    border-right: 1px solid #f0f4fa;
    box-sizing: border-box;
    cursor: pointer;
  }

  .register-completed-btn .do-login-btn {
    width: 50%;
    color: #4e537b;
    cursor: pointer;
  }

  .login-right-now {
    font-size: 16px;
    color: #A7B3C9;
    text-align: center;
  }
</style>
