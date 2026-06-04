inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR + "紅" + HIY + "黃" + HIC + "晶魂" + NOR, ({"red_yellow","red","yellow"}) );
        set("long","天靈地界中，「金風舞夢旋」所缺的紅色與黃色晶魂。(鑲魂方式 insert )\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_sec",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_steal",1);
        set("no_save",1);
        set("no_get",1);
        set("unit", "顆");
        set("value", 500000);
        set("base_weight", 50);
        setup();
}
void init()
{
        add_action("do_insert", "insert");
}
int do_insert(string str)
{
        object ob,me,ob1,*aob;
        int i,j;
        me=this_player();
        ob=this_object();
        if( !str ) return 0;
        aob = all_inventory(me);
        i=sizeof(aob);
        if( str == "red_yellow" )
        {
        for( j=i-1;j>=0;j-- )
        {
          if( aob[j]->query("red_yellow") )
          ob1 = aob[j];
        }
        message_vision(ob->query("name")+HIW + "漸漸的與$N手中的"+ob1->query("name")+HIW + "融合成一體。\n\n" + NOR,me);
        message_vision(ob1->query("name")+HIW + "上的" + HIR + "紅" + HIW + "、" + HIY + "黃" + HIW + "、" + HIC + "藍" + HIW + "三色晶發出了奪目的光彩。\n\n" + NOR,me);
        message_vision(HIW + "光彩過後"+ob->query("name")+HIW + "漸漸的消失無蹤了。\n\n" + NOR,me);
        me->set("weapon/change2",1);
        me->set("weapon/change3",1);
        destruct(ob);
        }else{
        message_vision(ob->query("name")+HIW + "在$N手中使不上力的感覺。\n" + NOR,me);
        }
        return 1;     
}
int query_autoload()
{
return 1;
}

