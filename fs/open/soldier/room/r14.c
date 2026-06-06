
inherit ROOM;

void create()
{
        set("short", "戰備處");
	set("long", @LONG

    這裡三面都是牆﹐南倒是路的盡頭了嗎??你突然發現
上面有微微的燈光﹐莫非上面還有路走～你眼睛瞄了一下
發現在旁邊有繩索(cord)通到上面﹐在面前也有一座長樓
梯(stairs)通到上面﹐在另一邊牆(wall)特別低﹐這時你
終於遇到人生的轉折點了。。。

LONG
);

  set("exits", ([ /* sizeof() == 2 */
    "northeast" : __DIR__"r11",
]) );
  set("item_desc", ([ /* sizeof() == 3 */
  "cord" : "一條細細的繩子,你可以爬爬(creep)看。\n",
  "wall" : "一面高而挺拔的白牆,你可以爬爬(mount)看。\n",
  "stairs" : "一個高大的竹梯,你可以爬爬(upper)看。\n",
]));

  set("light_up", 1);
  setup();
}

void init()
{
  add_action ("do_creep","creep");
  add_action ("do_upper","upper");
  add_action ("do_mount","mount");                                                                                                                    
}

int do_creep (string str)
{
  object	me;
  if (!str || (str != "cord" && str != "繩" && str != "繩子"))
    return notify_fail("你發覺自己不成才..想要上吊自盡了。\n");

  me = this_player();
  message_vision("$N兩手抓住繩索﹐使勁的往上爬去。\n", me);
  message_vision("沒多久$N又掉下來了。。。\n", me);
  me->move(__DIR__"r14"); 
  return 1;
}
 
int do_upper (string str)
{
  object	me;
  if (!str || (str != "stairs" && str != "長樓梯" && str != "樓梯"))
    return notify_fail("你是噸位太重嗎??\n");

  me = this_player();
  message_vision("$N輕輕的踏上樓梯﹐慢慢的往上爬去。\n", me);
  message_vision("$N發覺樓梯怪怪的..咚一聲～～像香蕉般的砸在地上了。。。\n", me);
  me->move(__DIR__"r14");
  return 1;
}
int do_mount (string str)
{
  object	me;
  if (!str || (str != "wall" && str != "牆"))
    return notify_fail("你發覺自己又不是蜘蛛人..幹嘛爬上去。\n");

  me = this_player();
  message_vision("$N像壁虎般往上爬﹐動作神迅猶如扒仔。\n", me);
  message_vision("$N爬到一半忽然覺的自己像神般的神～～。。\n", me);
  me->move(__DIR__"r19");
  tell_room(environment(me), sprintf ("%s像神般的爬了上來。\n",
	me->short()), me);
  return 1;
}
