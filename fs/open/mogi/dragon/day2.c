//by casey

inherit ROOM;

void create ()
{
  set ("short", "一線天");
  set ("long", @LONG
這裡是炎龍谷裡最狹窄的地方 ,往裡面去是龍族的棲息
之地 ,但是通路似乎被延長出來的藤蔓(rattan)給封閉
住了,看還要撥開才能往前行了...

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("evil", 1);
  set("no_auc", 1);



  set("item_desc", ([ /* sizeof() == 1 */
  "rattan" : "這裡的藤蔓似乎長的特別的茂密，密到完全掩蓋\住了山壁。
",
]));
         set("exits", ([ /* sizeof() == 1 */
  

  "south" : __DIR__"d-2",
]));


  set("search_desc", ([ /* sizeof() == 1 */
  "rattan" : "你撥開藤蔓，猛然發現後面竟然有個通道，但從外觀上卻完全看不出來。
或許\你能通過(pass)它。
",
]));


  setup();
}

void init()
{
        add_action("do_pass", "pass");
}

int do_pass(string arg)
{
        object who;
        who = this_player();

        if( !arg || arg!="rattan" )
                return notify_fail("你要通過什麼？\n");
        tell_object(who,"你用手撥開藤蔓，向後面的通道走了進去。\n");
        who->move("/open/mogi/dragon/b10.c");
        tell_room(this_object(),"你看到"+who->query("name")+"慢慢向藤蔓走去，忽
然就不見蹤影了。\n");
        return 1;
}

