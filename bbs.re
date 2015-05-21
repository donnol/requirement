需求
     1 发帖： 标题＋内容（不少于5字）＋图片（最多9张）
                 没有删除，没有修改
                 直接输入则新建楼层，楼层数从1开始递增
                 帖子回复数计算

     2 帖子详情：头像＋名字＋时间＋内容＋图片（最多9张）
                         评论可翻页，先发在前，后发在后，点击楼主，只看楼主
                
     3 板块：  名称＋一句话描述＋图标＋介绍   
                    后台可设置人气榜，拥有删帖权
                    板块内可设置排序方式
                    置顶及加精，最热 －－置顶贴之间可由后台设置顺序
                    帖子列表：标题＋用户＋时间（以发布时间（无回复）或最新回复时间（有回复）为准) + 评论数

     4 主页：轮播广告
                    板块列表：
                         版块显示：图标，名称，介绍

接口
     community => 
          detail() 
               bannerAo->getAll()
               topicAo->getAll() 
     topic => 
               topicAo => 
                    getAll() 
                    getBatchDetail($topicIds, $clientId=0, $postSize)
                    getDetail($topicId, $clientId=0, $postSize)
                    add(array(’name’,’image’,’introduce’,’sort'))
                    del($topicId)
                    move($topicId, $direction)
                    mod($topicId, array(...))
                    search(array(...), array(...))
                    setTopPost($topicId, array(topicPostId...))
                    setPopular($topicId, array(clientId...))
     post => 
               postAo => 
                    getBatchBrief($topicPostIds, $clientId=0, $floorSize)
                    getBatchDetail($topicPostIds, $clientId=0, $floorSize)
                    getDetail($topicPostId, $clientId=0, $floorSize)
                    addPost(array(‘topicId’, ‘clientId’, ’title’, ‘isTop’, ’sort’, ’text’, ‘image’))
                    del($topicPostId)
                    addFloor(array($topicPostId,...))
                    search(array(), array())

     t_topic_banner => 
         topicBannerId, title, image, link, remark, sort, createTime, modifyTime
     t_topic_client => 
          topicClientId, topicId, clientId, createTime, modifyTime   
     t_topic => 
          topicId, name, image, introduce, sort, createTime, modifyTime 
     t_topic_post => 
          topicPostId, topicId, clientId, title, isTop, sort, lastReplyTime, createTime, modifyTime 
     t_topic_floor => 
          topicFloorId, topicPostId, floorNum, clientId, text, image, createTime, modifyTime

select * from t_topic_post where topicId = ? order by lastReplyTime limit n, m;
