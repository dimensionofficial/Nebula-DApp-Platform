import request from '@/api/request.js'

/*
* 登陆接口
* */
export function login(params) {
  return request({
    url: '/login', 
    method: 'post',
    params // {name：string, password:string}
  })
}

/*
*  检查用户名是否已存在
* */
export function checkUser(params) {
  return request({
    url:'/check',
    method: 'GET',
    params // {name：string}
  })
}

/*
* 新增用户
* */
export function addUser(params) {
  return request({
    url: '/add',
    method: 'post',
    params // { name: string,password:string,address:string }
  })
}

/* 用户激活 */
export function activateUser(params) {
  return request({
    url: '/activate',
    method: 'post',
    params // {name:string,code:string}
  })
}

// 随机获取代币
export function random(params) {
  return request({
    url: '/random',
    method: 'get',
    params // {name: string}
  })
}
// 获取图形验证码 
export function getImgCode(params) {
  return request({
    url: '/imgcode',
    // withCredentials : true,
    method: 'get',
    params
  })
}
// 校验图形验证码 
export function checkImgCode(params) {
  return request({
    
    url: '/checkimgcode',
    // withCredentials : true,
    method: 'get',
    params //{code:string},
    
  })
}
// 获取激活码 
export function getNumCode(params) {
  return request({
    url: '/code',
    method: 'get',
    // withCredentials : true,
    params //{name:string}
  })
}
// 校验激活码 
export function checkNumCode(params) {
  return request({
    url: '/checknumcode',
    method: 'post',
    // withCredentials : true,
    params //{name:string,code:string}
  })
}

// 修改密码 
export function changePass(params) {
  return request({
    url: '/retrieve',
    method: 'post',
    params //{name:string,code:string,password:string}
  })
}
export function index() {
  return request({
    url: '/index',
    method: 'get',

  })
}
// 获取用户账户明细列表 
export function messagelist(params) {
  return request({
    url: '/messagelist',
    method: 'get',
    params //{name:string}
  })
}
