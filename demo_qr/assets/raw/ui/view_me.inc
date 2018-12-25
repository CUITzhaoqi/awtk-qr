    
    <view w="100%" h="100%" layout="r1 c0 m20" >
      <list_view x="40"  y="10" w="100%" h="-80" item_height="50">
        <scroll_view name="view" x="0"  y="0" w="100%" h="100%">
          <list_item style="odd_clickable" layout="r1 c0 s2 m2">
            <image draw_type="icon" w="60" image="setting"/>
            <label style="green" x="r:10" w="-60" text="账号管理">
              <view x="r:5" y="m" w="60" h="20">
                <image draw_type="icon" x="r" y="m" w="60" h="20" image="detailed"/>
                <image draw_type="icon" x="r:30" y="m" w="60" h="20" image="qq_lab"/>
              </view>
            </label>
          </list_item>
          <list_item style="odd_clickable" layout="r1 c0 s2 m2">
            <image draw_type="icon" w="60" image="setting"/>
            <label style="green" x="r:10" w="-60" text="手机号码">
              <view x="r:5" y="m" w="60" h="20">
                <image draw_type="icon" x="r" y="m" w="60" h="20" image="detailed"/>
                <label style="green" x="r:30" y="m" w="180" h="20" text="184xxxxxx86"/>
              </view>
            </label>
          </list_item>
          <list_item style="odd_clickable" layout="r1 c0 s2 m2">
            <image draw_type="icon" w="60" image="setting"/>
            <label style="green" x="r:10" w="-60" text="关于">
              <view x="r:5" y="m" w="60" h="20">
                <image draw_type="icon" x="r" y="m" w="60" h="20" image="detailed"/>
                <label style="green" x="r:30" y="m" w="180" h="20" text="AWTK"/>
              </view>
            </label>
          </list_item>
        </scroll_view>
        <scroll_bar_m name="bar" x="right" y="0" w="6" h="100%" value="0"/>
      </list_view>

    </view>
