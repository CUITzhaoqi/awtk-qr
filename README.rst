AWTK-QR 
^^^^^^^^^^

.. image:: http://gitlab.zhaoqi.info/awtk/awtk-qr/badges/master/pipeline.svg

.. image:: http://gitlab.zhaoqi.info/awtk/awtk-qr/badges/master/coverage.svg

AWTK-QR是AWTK的二维码插件，主要用于演示如何扩展 `AWTK <https://github.com/zlgopen/awtk>`_。

如何使用
---------

首先克隆 awtk-qr

.. code-block:: bash

    git clone https://github.com/CUITzhaoqi/awtk-qr.git

然后更新子模块

.. code-block:: bash

    git submodule update --init --recursive -- "awtk"

目录树
>>>>>>>>

- awtk\\………………(awtk工程)
- demo_qr\\………………(二维码插件的示例代码)
- docs\\………………(相关文档)
- scripts\\………………(awtk的工具脚本)
- src\\………………(相关源码)

    + qr\\……………………(awtk-qr插件)

    - lib\\……………………(二维码编码库)
- test\\………………(插件的测试)
- .gitlab-ci.yml………………(持续集成脚本)
- .SConstruct………………(scons 脚本)

MACOS
>>>>>>>>>

如果没有安装scons和sdl2，请在终端运行下面的命令(假定已安装brew)：

.. code-block:: bash

    brew install scons sdl2

然后使用scons编译

.. code-block:: bash

    scons -j8

更新资源(详细见 `更新资源 <https://github.com/zlgopen/awtk/tree/master/scripts>`_:)

.. code-block:: bash

    python ./scripts/update_res.py all

运行

.. code-block:: bash

    ./bin/demo_awtk_qr

Ubuntu
>>>>>>>>>

如果没有安装scons和sdl2，请在终端运行下面的命令(假定已安装brew)：

.. code-block:: bash

    sudo apt-get install scons libsndio-dev libgtk-3-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev

然后使用scons编译

.. code-block:: bash

    scons -j8

更新资源(详细见 `更新资源 <https://github.com/zlgopen/awtk/tree/master/scripts>`_:)

.. code-block:: bash

    python ./scripts/update_res.py all

运行

.. code-block:: bash

    ./bin/demo_awtk_qr

Windows
>>>>>>>>>

(请先安装python2.7，scons和Visual Studio C++(版本>=2017)

编译运行(在命令行模式下，进入awtk-qr所在的目录，并运行下列命令)：

.. code-block:: bash

    scons -j8

更新资源(详细见 `更新资源 <https://github.com/zlgopen/awtk/tree/master/scripts>`_:)

.. code-block:: bash

    python ./scripts/update_res.py all

运行

.. code-block:: bash

    bin\demo_awtk_qr.exe

文档
--------

`如何扩展AWTK——以二维码控件为例 <docs/expandawtk/index.rst>`_

`如何将AWTK的二维码控件加入AWORKS <docs/aworksport/index.rst>`_

问题
--------

报告BUG
>>>>>>>>>

请访问 `issue <https://github.com/zlgopen/awtk/issues>`_:

许可证
---------

`awtk <https://github.com/zlgopen/awtk>`_: LGPLV2.1

`libqrencode <https://github.com/fukuchi/libqrencode>`_: LGPLV2.1


