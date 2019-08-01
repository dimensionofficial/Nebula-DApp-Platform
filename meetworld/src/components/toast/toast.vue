<template>
  
      <!-- 全局提示框 -->
      <div v-show="visible" class="dialog-tips dialog-center">
          <div>{{message}}</div>
      </div>
  
</template>
<script>
export default {
  data() {
    return {
      visible: false,
      message: ""
    };
  }
};
</script>
<style >
.dialog-tips{
    position: fixed;
    z-index: 100;
    width: 152px;
    height: 43px;
    line-height: 43px;
    background-color: rgba(0, 0, 0);
    color: #fff;
    opacity: 0.6;
    text-align: center;
    font-size: 12px;
}

.dialog-center {
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%)
}

</style>