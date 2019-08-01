/*手机号和邮箱格式验证*/
export function checkUserAccount(str) {
  let regPhone = /^1\d{10}$/;
  // regEmail = /^(\w-*\.*)+@(\w-?)+(\.\w{2,})+$/;
  return regPhone.test(str);
};

/*本地验证密码格式*/
export function checkPassFormat(str) {
  let regPass = /^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,16}$/;
  return regPass.test(str);
}
