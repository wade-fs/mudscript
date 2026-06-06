//劍聖系列的裝備目前尚不開放給玩家 所以補上no_save no_steal by blazakira 2010/10/27
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
object me=this_player();
int cor,kar,intt,spi,cps;
void create()
{
        set_name(HIY"劍聖手飾"NOR,({"kensai ring","ring"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","件");
        set("value", 0);
        set("material","gem");
        set("long","此為劍聖專用的手飾..似乎有強大的力量。\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_save",1);
        set("no_steal",1);
            set("armor_type","finger");
            set("armor_prop/armor",20);
        }
        setup();
}
void init()
{
     add_action("do_wear","wear");
     add_action("do_remove","remove");

}
int do_wear(string str)
{
     ::wear();
     if( query("equipped") )
     {
        kar = me->query("kar",1);
        cor = me->query("cor",1);
        cps = me->query("cps",1);
        spi = me->query("spi",1);
        intt = me->query("int",1);
message_vision(HIC"穿上劍聖手飾..神聖之力隴罩$N全身。\n"NOR,me);
        set_heart_beat(1);
     }
}
int do_remove(string str)
{
   if(str=="swordmaster ring" || str=="all" || str=="ring")
     if( query("equipped") )
     {
message_vision(YEL"$N脫下了劍聖手飾..神聖之力頓時消失。\n"NOR,me);
        set_heart_beat(0);
     }
}

void heart_beat()
{
object *enemy;
int i;
  if( !objectp(me) )
        {
        set_heart_beat(0);
        return;
        }
  if( me->is_fighting()&&query("equipped")&&me->is_busy() )
  {
enemy=me->query_enemy();
i=random(sizeof(enemy));

if( random(cor+cps+spi) > 70-random(kar+intt) )
    {
    me->delete_busy();
message_vision(HIW+"\n劍聖之力鏧籠罩$N全身..使其神清氣爽。
\n"+NOR,me);
    }
  }
  return;
}
