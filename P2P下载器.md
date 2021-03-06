﻿# P2P下载器



 1. **需求定档**：让网络上的任意两台主机之间可以互相下载共享文件
 2. 市场调研：
 3. 技术调研：
 4. 概要设计：
    1. 网络上的两台主机共享->必须知道网络上都有哪些主机能够与自己建立共享关系
    2. 从一指定的主机上去下载自己想要的文件，也可以将自己的文件提供给别人的下载

P2P下载器：
1. 包含两个大模块：
    1. 客户端模块：查看哪些共享主机+获取主机文件列表+从指定主机下载文件
    2. 服务端模块：针对客户端的请求提供客户端的请求服务

客户端： 
1. 查看网络中的共享主机 - 向网络中广播配对请求，得到响应
2. 选择一个主机获取文件列表-向指定主机发送获取文件列表请求
3. 下载指定文件- 向指定主机发送下载文件的请求


客户端：
1. 查看网络中的共享主机(局域网）
 1.作为客户端，广播一个主机配对请求，得到响应，则认为这个主机在线，可以获取共享文件。
 udp协议自带局域网广播功能(有可能丢包，保证可靠传输）
 tcp因为没有自带广播功能，所以必须知道所有主机的ip地址，才能发送请求。

如何获取局域网中所有的IP地址：
ip地址的组成： 网络号+主机号(0-最大的主机号）
获取网络号： 当前主机的ip地址与子网掩码相与
获取最大主机号： 子网掩码取反
网络号 + （1-最大主机号-1） 局域网中所有的ip地址，但是有可能有些主机没有连网，或者这些ip地址还没有被分配。

2. 向各个ip地址发送主机配对请求--网络通信
应用层网络通信协议的选择：
1. 自定制协议：
2. 知名协议-HTTP协议(用户拥有一定的自定制功能）
HTTP协议格式： 首行-头部-空行-正文

接口设计:

    1. 网络主机配对接口：  
    客户端：GET(获取信息功能） GET/hostpair（配对的请求） HTTP/1.1
    Content-Length: 0
    服务端： HTTP/1.1 200 OK
    Content-Length: 0
    得到主机在线。
    获取当前局域网中所有的在线主机ip地址列表
    2.获取文件列表接口（指定主机）
    客户端：Get/list HTTP/1.1
    Content-Length: 0
    服务器：HTTP/1.1 200 OK
    Content-Length: 
    正文： 所有共享的文件名称。(检索共享文件夹下的所有文件信息）
    filiename1filename2 数据粘包问题，分隔符分割'\r\n' 直接按行打印出来，后期扩展json序列化。
    客户端就获取到了指定主机上的所有共享文件名称。
    3. 下载指定主机上的共享文件
    文件下载接口设计：
    客户端： GET/fiilename HTTP/1.1
    Content-Length: 0
    服务器：
        1.文件是否存在
        2.这个文件是个目录
        3. 打开文件，将这个文件中的正文写到正文数据中
    HTTP/1.1 200 OK
    Content-Length: 文件大小(正文数据）
    正文：文件数据
    客户端：创建打开文件，将正文数据写进文件
    网络中的文件传输，实际上就是创建一个文件，将那个文件的数据写入这个创建的文件当中。关闭创建的这个文件。
    

总功能流程：
    
    客户端：
    1. 获取网卡信息-获取主机的ip+MASK--局域网ip列表
    2. 向所有的ip发送配对请求--得到在线的主机列表
    (将所有的ip列表打印到终端上，让用户看到)
    3.选择一个主机(ip）发送获取文件列表的请求--获取到共享文件列表(将文件的列表打印到终端，让用户看到)
    4.从这个主机ip下载指定的文件(文件名称）
    （创建这个文件，打卡它，将响应的正文数据写入文件中，关闭它）
    
    服务端：
    1.接收到主机的配对请求 则做出200响应，表明服务端在线
    2.接收到文件列表请求
        1. 检测获取指定共享目录下的文件信息
        2. 将所有的文件名组织成http响应正文
    3. 接收到指定的文件下载请求
        1. 通过文件名检测文件是否存在
        2. 检测文件是否为一个普通的文件
        3. 打开文件，读取数据作为http响应的正文响应给客户端。
        
        
客户端代码模块:
    
    
    Client
    {
    //获取在线主机，向所有的ip地址发送配对请求，判断是否在线。
    void hostPair(unit32_t ip) //直接向主机发送请求，判断其是否在线(多线程，线程入口函数）
    bool GetOnlineHost() // 1.获取网卡信息得到每一个主机的ip地址(得到主机IP地址的时候，
    再向每一个主机发送共享文件请求，**有些ip地址没有分配到个人，就没办法进行三次握手四次挥手建立连接，或者有的主机没有运行我们这个下载器，所以就接收不到我们的连接请求，那么它不没有开启这个端口，不会做出响应**）。2.创建线程，传入HostPair，判断是否在线（**每一个主机配对很慢，所以我们采用多线程配对的方式**）。
    bool GetShareList(uint32_t ip)// 获取指定主机的共享文件列表，打印出来让用户选择要下载的文件。
    bool DownloadFile(const uint32_t ip, const std::string& filename); //下载指定的文件。
    
    private:
    vector<uint32_t> _online_host_list //保存所有的在线主机ip信息。我们的在线主机列表支配对一次，**不能每次选择文件下载的时候都要进行主机配对，下一次的话这个数组不为空，则就不需要进行配对。**
    
}

服务端模块：
    
    Server
    {
    1. 搭建http服务器，对http请求的业务处理作出响应--使用第三方库实现 cpp-httplib.(**协议格式已经不用关注了，因为cpp-httplib库中实现的是遇到什么接口会回调什么函数，所以只针对业务做接口处理即可**)
    2. 针对客户端的功能请求进行业务处理接口的实现即可。
    
    void HostPair();//针对客户端的主机配对请求作出正确的响应。
    void ShareList();//针对客户端共享文件列表作出正确的响应。
    void Download(); //针对客户端的下载文件请求作出响应。
    
}


客户端在查看网络共享主机配对的是时候，应用层采取HTTP完成网络通信，网络通信传输层采取的是TCP协议，
向每一个主机广播这样的TCP请求包，但是必须知道局域网中所有的的ip地址才能这样做。


> 客户端模块的实现：
1. 实现一个主机的类
class Host
{
    uint32_t _ip_addr;
    bool _pair_ret;
}
2. 创建一个vector,先将所有的主机(所有的网卡)的地址实例化出一个对象，添加到vector中
3. 循环创建线程进行配对请求。
4. 循环等待线程退出，通过pair_ret判断这个主机是否配对成功，若成功则添加到在线主机列表中


我们在获取网卡信息的时候，采用多线程的方式，每一个线程都要等待，如果只获取一个网卡的局域网在线主机之后，循环等待这个网卡局域网中的线程退出，才能获取下一个网卡，这样就太慢了，所以我们需要获取所有网卡所在的局域网，将所有的ip添加到一个类中，然后线程去配对完之后，所有的线程进行循环线程等待。这样就减少了线程等待的时间。

主机配对三步走：
1. 创建vector<Host>,将所有的主机地址添加到vector中
2. 创建线程，进行配对
3. 等待线程退出，判断配对结果，将成功的添加到在线主机列表中

主机配对：
作为一个客户端，给其他服务端发送配对请求
1. 自身是一个客户端
2. 在应用层选用http协议

1. 组织一个http请求数据出来 GET/hostpair HTTP/1.1\r\n Content-Length:0
2. 搭建tcp客户端，与主机建立连接(**大部分主机都是没分配或者没有运行这个p2p**,一个主机需要3s中)，发送请求数据
3.等待服务端的回复响应，进行解析，判断状态码，200则为配对成功

cpp-httplib是一个C++封装的http库，使用这个库就可以完成客户端与服务端的搭建。
