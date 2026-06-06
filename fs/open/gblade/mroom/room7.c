// Room: /u/m/moner/room/room7.c
inherit ROOM;

void create ()
{
  set ("short", "內廳");
  set ("long", @LONG

一走進內廳，映入眼簾的便是一幅人像圖(picture)，兩旁襢香木椅散發著陣
陣的襢香，紫琉水晶燈將屋內點綴的像白晝一般，屋上方掛著一個香寰，上面的香
正裊裊的燒著，煙冉冉的繞著你飛舞，令你不知置身何處。屋中央的四色琉璃桌散
發著奇詭的色彩，放置其上的刀也相互輝映著。
  煙裊裊的升上半空，像中的人眼中散發著奇異的色彩....。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room1.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
"word" : "蒼天已滅，魔刀當立。\n",
  "picture" : "一幅人像圖, 圖中之人有八分似魔刀老人, 圖旁有一行小字(word)
",
]));
  set("light_up", 1);

  setup();
}
/*
void init()
{
        add_action("do_pray","pray");
  }
int do_pray(string arg )
{
        object ob;
        ob=this_player();
          if(ob->query("sen") > 20)
        {
message_vision("$N跪了下來,向人像圖磕了幾個響頭....\n",this_player());
 if(random(10)>8)
        {
call_out("do_act1",3,ob);
        return 1;
        }
        else
message_vision("$N心意不夠誠懇, 無法回應老人的心思..\n", this_player()
);
        return 1;
}
}
int do_act1(object ob)
   {
 message_vision("$N彷彿看到老人的眼中閃出一道光芒......
 
$N心中一震, 似有所晤...。\n\n",ob);
ob->add("bellicosity",1);
ob->add("sen",-40);
     return 1;
}
*/
