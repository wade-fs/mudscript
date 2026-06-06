// Room: /open/gblade/room/p-room1.c
inherit ROOM;
string do_look();

void create ()
{
  set ("short", "密室");
  set ("long", @LONG
陰暗封閉的密室，因長年無人涉足，而充斥著一股令人悶塞的氣息，
暗淡的光線穿過虛浮的塵埃，映在凹凸的岩壁上，隱約間可見密室中央放
著一個玄鐵盒(box)，黝黑的外表拖著長長的影子，直到幽暗的角落裡。

LONG);
        set("item_desc",([
        "box" : (: do_look :),
        ]));

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"p-room",
]));
  set("light_up", 1);

  setup();
}
void init()
{
        add_action("do_break","break");
}
string do_look()
{
        if(this_player()->query("lotch")>3)
        return "你發現盒子內空空如也 , 哪有什麼煉妖壺 !\n";
        if(this_player()->query("lotch")<2)
        this_player()->set("lotch",2);
        return "
這個盒子為千年玄鐵所製 ,看來非得找一把神兵利器才能將它打(break)
開! 難不成裡面藏著傳說中的煉妖壺 ? \n";
}
int do_break(string str)
{
        if(!str||str!="box")
        return notify_fail("你要打開什麼 ?\n");
        if(!present("dragon-tiger blade",this_player() ) )
        return notify_fail("找到龍虎刀再說吧 !\n");
        if(this_player()->query("lotch")>3)
        return notify_fail("這個盒子已經被你打開了 !\n");
        message_vision("$N手持龍虎刀 , 往盒子一砍 !\n",this_player() );
        message_vision("千年玄鐵為龍虎刀所破 , $N將盒子打開 !\n",this_player()
 );
        this_player()->set("lotch",4);
return 1;
}
