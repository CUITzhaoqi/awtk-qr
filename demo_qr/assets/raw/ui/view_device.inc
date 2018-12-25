
    <view w="100%" h="100%">
      <label x="-30" y="0" w="30%" h="60" text="我的设备" /> 
      <image x="10" y="0" draw_type="icon" w="60" image="device"/>
      <list_view x="40"  y="50" w="70%" h="-80" item_height="50">
          <scroll_view name="view" x="0"  y="0" w="100%" h="100%">
            <list_item style="even" layout="r1 c0">
              <image draw_type="icon" w="60" image="device"/>
              <label style="green" x="r:10" w="-60" text="MAC:BB:BB:BB:BB:BB:BB">
                <switch x="r:10" y="m" w="60" h="20"/>
              </label>
            </list_item>
            <list_item style="odd" layout="r1 c0">
              <image draw_type="icon" w="60" image="device"/>
              <label style="green" x="r:10" w="-60" text="MAC:AA:AA:AA:AA:AA:AA">
                <switch x="r:10" y="m" w="60" h="20"/>
              </label>
            </list_item>
          </scroll_view>
          <scroll_bar_m name="bar" x="right" y="0" w="6" h="100%" value="0"/>
        </list_view>
    </view>
