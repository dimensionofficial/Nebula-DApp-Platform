// import axios from 'axios'

// create an axios instance
const service = axios.create({
  baseURL: 'http://47.100.54.105:9001', // api的base_url,可自己定义
  timeout: 5000 // request timeout
});

// request interceptor
service.interceptors.request.use(config => {
  // Do something before request is sent
  config.withCredentials = true
  return config
}, error => {
  // Do something with request error
  console.log(error);// for debug
  Promise.reject(error)
});

// respone interceptor
service.interceptors.response.use(
  response => {
    const res = response.data;
    // console.log(res);
    // if(typeof(res) === 'boolean') {
    //   return response
    // }
    if (res.code !== 200) {
      return response
      // return Promise.reject(res.message)
    } else {
      return response
    }
  },
  error => {
    console.error('err' + JSON.stringify(error));// for debug
    // Message({
    //   message: '登陆超时，请重新登陆',
    //   // message: error.message,
    //   type: 'error',
    //   duration: 5 * 1000
    // });
    return Promise.reject(error)
  });

export default service
