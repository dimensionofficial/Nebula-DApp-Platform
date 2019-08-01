<template>
<div>
  <h1>{{$t('welcome')}}</h1>
  <div class="passLogin">
      <el-form :model="ruleForm" status-icon :rules="rules" ref="ruleForm" >

      <el-form-item  prop="email">
        <el-input type="e-mail" v-model="ruleForm.email"  :placeholder="$t('inputEmail')"></el-input>
      </el-form-item>

      <el-form-item  prop="pass">
        <el-input type="password" v-model="ruleForm.pass"  :placeholder="$t('pass')"></el-input>
      </el-form-item>
      

      <el-form-item>
        <el-button class="submit" :class="[ 1 < 2 ? 'primary' : 'info' ]" type="primary" @click="submitForm('ruleForm')">{{$t('login')}}</el-button>
      </el-form-item>
    </el-form>
  </div>

  <!-- <form action="">
    <div class="kuang">
      <input type="e-mail" placeholder="请输入您的邮箱">
      <p></p>
    </div>
    
    <div class="kuang">
      <input type="password" placeholder="请输入您的密码">
      <p></p>
    </div>
    
    <button class="login">登录</button>
  </form> -->

</div>
</template>

<script>
import {login} from '@/api/api'
  export default {
    data() {
      var validateEmail = (rule, value, callback) => {
        if (value === '') {
          callback(new Error(this.$t('inputEmail')));
        } else {
          if (this.ruleForm.email !== '') {
            this.$refs.ruleForm.validateField('email');
          }
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
          login: 'false'
        },


        rules: {
          pass: [
            { validator: validatePass, trigger: 'blur' }
          ],
          email: [
            {  required: true, message: this.$t('inputEmail'), trigger: 'blur'  },
            { type: 'email', message: this.$t('inputCorrentEmail'), trigger: ['blur', 'change'] }
          ],

        },

      };
    },
    methods: {
      submitForm(formName) {
        this.$refs[formName].validate((valid) => {
          if (valid) {
            // alert('submit!');
            var that = this
            login({
              name:that.ruleForm.email,
              password:that.ruleForm.pass,
              token:JSON.parse(localStorage.getItem('token')).token
              }).then(function(res){
                  console.log(res)

                if(res.data.code == 200){
                  console.log(res)
                  const info = { isLogin:true,name:that.ruleForm.email };
                  localStorage.setItem('info', JSON.stringify(info));
                  that.$toast(that.$t('loginS'));
          that.$emit('closeclose');
                  
                  // console.log(abc)
                  // that.$router.push({path: '/'});
                }else if(res.data.code == 500){
                  that.$toast(that.$t('loginF'));
                }


            }).catch(error => {
              console.log(error)
            })
          } else {
            console.log('error submit!!');
                  

            return false;
          }
        });
      },
     
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

  .tu{
    background-color: #ccc;
    height: 40px;
    line-height: 40px;
    width: 25%;
    display: inline-block;
    margin-left: 10%;
    text-align: center;
  }
</style>
