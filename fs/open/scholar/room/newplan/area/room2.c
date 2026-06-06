// Room: /u/s/sueplan/newplan/area/room2
inherit ROOM;

void create ()
{
  set ("short", "天機星");
  set ("long", @LONG
姜尚又名姜子牙，居住於崑崙山的深山裡，向元始天尊學習仙道，
獲得甚多的智慧。運氣未到以前，無論哪一個英雄、賢哲、軍師都和凡
人完全一樣。姜尚到老年一直過著懷才不遇的生活。他的不幸，可以說
受到了配偶的影響。因為他和一位姓馬的小姐結婚，所以一輩子赤貧如
洗。但是到了老年，他倆彼此同意離婚，各走各人的路。從那個時候起
，姜尚才開始走了紅運。他每天一人在湖邊垂釣，偶而被文王發現他的
才能，任周國軍師。姜尚一向愛國忠王，文王死後也仍然輔佐武王，竭
力強國富國。因為他的智慧過人，可以預測未來，適應現在，所以他才
被任命為周日的軍師。                                                   武王稱霸天下以後，姜尚受封為齊國諸侯，不幾年他終於逝世
了，他的靈魂被太白金星攜回天界，永住於天機星。從此，天機星掌管
紫薇斗數中的『智慧』。 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_kao.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room3.c",
  "south" : __DIR__"room1.c",
]));

  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="enter"&&present("scholar",environment(me)))
    {
    return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
     }
  return 1;
}
