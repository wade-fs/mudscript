// Room: /u/s/sueplan/newplan/area/room8
inherit ROOM;

void create ()
{
  set ("short", "太陰星");
  set ("long", @LONG
紂王手下有個盡忠的黃飛虎將軍。黃飛虎的妻子年輕貌美，在殷朝
的天下是唯一能和妲己相比的美人。因此，妲己心哀很不高興。黃飛虎
的太太又被稱賈女人。                        
    殷朝時代，每逢過年那一天，諸大臣和將軍都必須夫妻同行，進宮
向君主拜年。追是一種傳統的慣例。賈夫人也跟隨黃飛虎將軍進宮拜年
。這時，妲己頓起邪念，懇請紂王准許他和賈夫人留宮聊天。黃將軍便
獨自先回家了。                                                    
    妲己誘賈夫人登上宮中高樓，然後造成機會，使賈夫人單獨和紂王
面對樂宴。紂王一喝酒，便失去埋智，起了好色的本性，想非禮這位絕
世美人。貌美的賈夫人又是一位貞節聞名的女性，當然推辭拒絕紂王的
淫言亂行。紂王憑藉酒勢，東追西抓，使賈夫人奔跑躲開而失足墮落。
貞節拒淫的賈夫人一墜便死。太白金星見她貞節超人，就把他的靈魂帶
回天界。                  
    賈夫人除貞節外，還具有潔白的個性。無論給她那一星座，她總是不
表示同意。太白金星不得不請她住在清幽的月球上，把月球叫做太陰星。
在月球上的『太陰』神賈夫人便從此掌管『清潔』和『住宅』。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/scholar_hace.c" : 1,
]));
  set("light_up", 1);
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room9.c",
  "south" : __DIR__"room7.c",
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
