// Room: /open/gsword/room/g6-11
inherit ROOM;
void create ()
{
  seteuid(getuid());	// 不是說要加這一行嗎?
  set ("short", "山洞");
	set( "build", 18 );
  set ("long", @LONG
這個洞穴頗大，往東往西往北都有一個較小的石穴，洞內瀰漫著一種
說不出的詭異氣氛，時有聽到動物慘叫的聲音，時而聞到濃厚的血腥味道
令你不寒而顫。
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"g6-10",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/obj/gstatue1.c" : 1,
]));
  
  setup();
}

void init()
{
 add_action("cut_hand","cut");
 add_action("do_enter","blood");
}
 
int cut_hand(string str)
{
  object ob,ob1;
  ob=this_player();
  if(!present("statue",environment(ob)))
    return notify_fail("你割這麼多次幹嘛 ,失血過多不好哦.\n");
  if( str!="hand")
    return notify_fail("叫你割手啦 ,你在割哪啊!!\n");
  message_vision("一柱鮮血自$N手腕噴出 ,往雕像激射而去.....      \n ",ob);
  write("\n\n\n");
     ob1=present("statue",this_object());
  destruct(ob1);
  call_out("msg1",3,ob);
  return 1;
}   

int do_enter(string str)
{
   object me = this_player();
  if(me->query("bloodsword")==1)
   me->move("/open/gsword/room1/blood/room3/r5.c");
   return 1;
}
int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("只見雕像手指微動 ,臉色漸轉紅暈\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  object ob1;

  message_vision("突然老祖眼睛一張 ,一座雕像竟爾復活了 ,嚇的$N連退三步..\n",ob);  
  message_vision("老祖道: 小子謝謝你啦.....\n",ob);
  message_vision("老祖一個箭步衝到洞口 ,蹤身一躍 ,身影消失在山谷中\n",ob);
  ob1=new("/open/gsword/mob/bigghost");
  ob1->move("/open/gsword/room/test");
  message("mud","一陣開山裂地的笑聲自蜀山中傳出..\n\n\n",users());
  message("mud","綠毛老祖吼道: \n
      哈 哈 哈......蠢蛋"+ ob->query("name")+"\n
   使的老子我終於得以重現江湖 \n
          仙劍派的龜孫子們 ,抹乾淨你們的脖子 ,靜待死神的來臨吧 ,\n
              我要  血  洗  仙  劍  !!!!\n \n",users());
  call_out("msg3",3,ob);
  return 1;
}

int msg3(object ob)
{
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road8");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road6");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road4");
 new("/open/gsword/mob/bloody")->move("/open/gsword/room/road6");
 new("/open/gsword/mob/bloody")->move("/open/gsword/room/road4");
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road4"); 
 new("/open/gsword/mob/gghost")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/road1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/rroad1");
 new("/open/gsword/mob/ghost1")->move("/open/gsword/room/lroad1");
 message("mud","老祖已經復活了 ,\n
     小鬼們 ,咱們殺上仙劍替老祖洗塵..\n",users()); 
  call_out("msg4",3,ob);
  return 1;
 }
int msg4(object ob)
{
  message("mud","鄭士欣嘆道:\n

     唉...真是一場冤孽...
           眾子弟們 ,讓我們齊心化解這場百年前所重下的因果..\n",users());
  
  return 1;
}                      
