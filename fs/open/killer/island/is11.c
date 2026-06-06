// Room: /u/u/unfinished/room/is11.c
inherit ROOM;

void create ()
{
  set ("short", "小瀑布");
  set ("long", @LONG
來到這裡, 此處的樹木已沒有那麼的鬱密遮天. 此地三面被山壁所包圍, 少
量的水源從東面的山壁流出, 形成一條小瀑布(waterfall),看來就算短時間內船
隻無法修復, 飲水應該也不成問題了. 這裡三面是山, 一面是森林, 海風不侵, 
十分暖活.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "waterfall" : "一條由山壁流出的小瀑布,水質澄清,並非海水,用來飲用(drink)應該沒問題.
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"is10",
]));
  set("outdoors", "/u/u");

  setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink()
{
        object who;
        who = this_player();
                  if ((int)who->query("water") >= (int)who->max_water_capacity())
          {
            tell_object(who,"喝那麼多水幹麻?!亂喝水小心長蛔蟲!!\n");
            return 1;
          }
            tell_object(who,"\n你從瀑布中喝了一些水....味道不是很好!!\n");
            who->add("water",50);
            return 1;
}
