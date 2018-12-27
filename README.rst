AWTK-QR
^^^^^^^^^^

AWTK-QR是AWTK的二维码插件，主要用于演示如何扩展 `AWTK <https://github.com/zlgopen/awtk>`_。

如何使用
---------

首先克隆 awtk-qr。

.. code-block:: bash

    git clone https://github.com/CUITzhaoqi/awtk-qr.git

然后更新子模块

.. code-block:: bash

    git submodule update --init --recursive -- "awtk"

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

问题
--------

报告BUG
>>>>>>>>>

请访问 `issue <https://github.com/zlgopen/awtk/issues>`_:

.. figure:: docs/img/test.jpg
    :name:  测试1运行图
    :align: center
    :width: 300px

    测试1运行图

许可证
---------

`awtk <https://github.com/zlgopen/awtk>`_: LGPLV2.1

`libqrencode <https://github.com/fukuchi/libqrencode>`_: LGPLV2.1


