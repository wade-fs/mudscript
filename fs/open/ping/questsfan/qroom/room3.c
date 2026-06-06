#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "虹晶橋後段");
  set ("long", @LONG
晶橋的後半段可能因為越來越接近另一岸了，同時也
較遠離斷崖中心了，其強勁的吸引力也緩和下來了。當你
踏到陸地的那一剎那、百感交集儼然覺得剛從鬼門關走了
一遭，但幸運的逛了回來了。哎！踩在陸地上的感覺真踏
實啊！！！

LONG);


        set("exits", ([ /* sizeof() == 1 */
  "north" : __FILE__,
  "south" : __FILE__,
]));

        set("objects", ([
]));
        setup();
}
void init()
{
        object me=this_player();

        message_vision(HIY"$N頓覺腳下有異，低頭一看，才發現自己正身處在空虛之中，$N還來不及反應，身子已經筆直的跌入谷中!!!\n"NOR,me);
        me->set_temp("last_damage_from",me);
        me->set_temp("kill_it_self",1);
      tell_object(users(),HIR"
「啊～～～～～～～～」的一聲慘叫, 從段家的後山傳出, "+me->query("name")+"不慎失足跌落深谷,
屍骨無存!!!\n"NOR);

        me->die();
        call_out("do_clean",2);
}
int do_clean()
{
    object *inv;
    int i;

    inv=all_inventory(this_object());
    for(i=0;i<sizeof(inv);i++){
      if(!inv[i]) continue;
      destruct(inv[i]);
    }
    return 1;
}
