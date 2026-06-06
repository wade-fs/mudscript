inherit ROOM;

void create ()
{
  seteuid(getuid());
  set ("short", "血魔殿");
  set ("long", @LONG
此地隨處可見遍地斷牆殘壁....實在很難想像是當初轟動一時的天魔轉世體
血魔的宮殿，只見這裡除了一道道的的符咒之外...在角落你可看到一攤奇形怪狀
的血漬(blood).....似乎有著一些秘密....
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "blood" : " 一灘奇形怪狀的血漬\n",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/gsword/room1/blood/room3/r3.c",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "blood" : "你仔細看了這灘血漬，赫然發現血漬竟然被一道到符咒(taoistfigure)為在中央並在符咒中蠢蠢欲動..似乎在較你撕開(tear)它。\n",

]));
  setup();
}
void init()
{
 add_action("do_tear","tear");
}
int do_tear(string str)
{
  object ob,ob1;
  ob=this_player();
  if( str!="taoistfigure")
    return notify_fail("撕符咒啦....你天兵歐...!!\n");
  if(ob->query_temp("blood1")!=1)
    return notify_fail("吃大便去...沒開封印也想解...!!\n");
  if(ob->query_temp("killtiger")!=1 && ob->query_temp("killdragon")!=1)
    return notify_fail("沒完全解迷也想來放血魔...你找死ㄚ...!!!\n");
message_vision("你一張一張的撕開貼在血漬上方的符咒...\n ",ob);
    ob->set("swordplus",1);
  ob->set("bloodsword",1);
  ob->delete_temp("killtiger");
  ob->delete_temp("killdragon");
  ob->delete_temp("blood1");
log_file("sword/broken",sprintf("%s(%s) 解放血魔 on %s\n",ob->query("name"),ob->query("id"),ctime(time()) ));


  call_out("msg1",3,ob);
  return 1;

}

int msg1(object ob)
{
 message_vision("\n",ob);
 message_vision("血漬漸漸產生血光...並一步一步的組成人形..\n",ob);
  call_out("msg2",3,ob);
  return 1;
}

int msg2(object ob)
{
  object ob1;

  message_vision("突然...一道道無與倫比的魔氣由四面八方射入削人中...嚇得$N站不直..\n",ob);

  message_vision("血魔道: 小鬼....實在是太感謝你了.我總算出封印了.\n",ob);
  message_vision("到綠毛老祖的石雕像那來找我吧..(blood)我暫時會在那..\n",ob);
  message_vision("只覺一道血光劃過眼前....血魔已經消失無蹤了...\n",ob);
   this_player()->move ("/open/gsword/room/g6-5.c");
   this_player()->set("title","仙劍劍俠--(暗藏魔氣)--");
  message("mud","一陣陣開天闢地的笑聲自蜀山奇陣中傳出..\n\n\n",users());

  message("mud","血魔狂叫道: \n
      哈 哈 哈......封印多年...總算有人來把我放出去啦~~~真是好樣的
      逍遙子、風青雲你們給看著吧...我會找你們報仇的    
          我  的  子  弟  們  將  血  洗  武  林  \n ",users());
  call_out("msg3",3,ob);
return 1;

}

int msg3(object ob)
{
  message("mud","鄭士欣嘆道:\n

     天~~~師祖與師叔的封印被破....唉~~想不到仙劍竟然有叛徒

           天祐仙劍.就請師祖們再次顯靈了....\n",users());

  return 1;
}
