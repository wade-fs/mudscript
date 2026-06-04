#include <ansi.h>
#include <armor.h>
#define MASTER "enter"
inherit ITEM;
inherit SSERVER;
object me;
string LONG_STRING="
靈界寶物，使用者需以本身能量注入其中，待能量充足時，可以將其中能量釋放出來
予敵致命的一擊。
dowear hoan是穿戴
doremove hoan是解除
docheck hoan是看看裡面聚的能量有多少
doshoot xxx是讓xxx死,條件是hoan裡的能量要大於xxx的exp
power_change 點數可以讓你身上的點數轉換為內力(1:5)
";
string NAME;
void create()
{
     set_name(HIC + "魔封環" + NOR ,({"mo_fon_hoan", "hoan"}));
     set_weight(2500);
     set("no_auc",1);
     set("no_sell",1);
     set("no_put",1);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_steal",1);
     set("no_save",1);
     set("light_up",-1);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long",LONG_STRING);
            set("unit", "件");
            set("value",50000);
            set("material","gold");
            set("armor_prop/armor",7);
            set("light",1);
           }
        setup();

}
void init()
{

        string user_id;

        me=this_player();
        user_id=getuid(me);
        NAME=this_object()->query("name");
        if(user_id!=MASTER && !wizardp(me) && userp(me))
        {
                write_file("/u/b/bss/record/hoan",
                sprintf("%s 用了 %s的魔封環 at %s\n",user_id,MASTER,ctime(time())));
                write("你不是我的主人，無法使用我!!\n");
                destruct(this_object());
        }
        else
        {
                if(!me->query("mo_fon_hoan"))
                {
                me->set("mo_fon_hoan/point",0);
                me->set("mo_fon_hoan/killer",0);
                }
        }
        if( environment() == this_player() ){
        add_action("do_wear","dowear");
        add_action("do_remove","doremove");
        add_action("do_check","docheck");
        add_action("do_shoot","doshoot");
        add_action("do_chpower","power_change");
        }
}
int do_wear(string arg)
{
        if(!arg) return 1;
        if(arg=="hoan" || arg==query("id"))
        {
        if(me->query_temp("using_hoan"))
                return notify_fail("你正在使用中!!\n");

        message_vision("$N將$n吸在嘴裡，眼前忽然為之一亮，似乎看得更清楚些了!!\n",me,this_object());
        set("short", sprintf ("吸在嘴裡的%s(%s)",name(),query("id")));
        me->set_temp("using_hoan",1);
        me->set_temp("def_fire",1);
        set("had_light",1);
        set_heart_beat(1);
        }
        return 1;
}
int do_remove(string arg)
{
        if(!arg) return 1;
        if(arg=="hoan" || arg==query("id"))
        {
        if(!me->query_temp("using_hoan"))
                return notify_fail("你沒有在使用中!!\n");
        message_vision("$N將$n從嘴裡拿了出來!!\n",me,this_object());
        me->delete_temp("using_hoan",1);
        me->delete_temp("def_fire");
        delete("short");
        delete("had_light");
        set_heart_beat(0);
        }
        return 1;
}
int do_check(string arg)
{
        if(!arg) return 1;
        if(arg=="hoan" || arg==query("id"))
        {
        printf(this_object()->query("name")+"目前的能量為:%d\n",me->query("mo_fon_hoan/point"));
        printf(this_object()->query("name")+"使用過的次數為:%d\n",me->query("mo_fon_hoan/killer"));
        }
        return 1;
}
int do_shoot(string arg)
{
        int self_point,target_exp;
        object target;
        if(!userp(me)) return 0;
        if(!arg) return notify_fail("你要封印誰?\n");

        if(environment(me)->query("no_fight")==1 )
                return notify_fail(this_object()->query("name")+"在這似乎發揮不了作用。\n");
        if(!(target = present(arg, environment (me))) )
                return notify_fail ("沒這個人\n");
        if(target->query("no_kill"))
                return notify_fail(this_object()->query("name")+"對"+target->query("name")+"無法產生任何影響!!\n");
        if(target==me)
                return notify_fail("你要對付自己???\n");
        if(in_edit(target) || in_input(target) || target->query_temp("net_dead"))
                return notify_fail("還是不要在別人忙碌的時候打擾別人比較好喔!!\n");
        if(target->query("age") < 16)
                return notify_fail("對方年紀還小，可禁不住你這一封的!!\n");
        self_point=me->query("mo_fon_hoan/point");
        target_exp=target->query("combat_exp");
        if(self_point <= target_exp)
                return notify_fail(NAME+"所儲存的能量不夠!!\n");

        if(target->query_temp("pk_fight"))
                return notify_fail("你無法對他使用!!\n");

        message_vision("
        $N將"+NAME+"拿在手上，對著$n大聲的喊道:

        「$n！！！下地獄去吧！！！」

        魔～～～～～封～～～～～環

        只見$N的手掌發出一道刺眼的藍光，朝$n直射而去
        ",me,target);

        message_vision("$N慘被藍光擊中，眼前忽然一黑，失去了所有知覺!!\n",target);
        target->set_temp("last_damage_from",me);
        if(target)
        target->unconcious();
        target->set_temp("last_damage_from",me);
        if(target)
        target->die();
        me->set("mo_fon_hoan/point",0);
        me->add("mo_fon_hoan/killer",1);
        return 1;
}
int do_chpower(string arg)
{
    object me;
    int point,max_force;

    me=this_player();
    if(!arg) return notify_fail("command:power_change 點數\n");
    if(!sscanf(arg,"%d",point))
      return notify_fail("command:power_change 點數\n");

    if(point > me->query("mo_fon_hoan/point"))
      return notify_fail("魔封環裡面沒有那麼多點數!!!\n");

    if(!point) return notify_fail("點數為零???不想轉換就不要轉換嘛!!\n");
  
    if(point < 0)
      return notify_fail("負的點數???只能用正的點數啦!!\n");

    max_force=me->query("max_force");
 
   if(me->query("force") + point * 5 > max_force * 10)
      return notify_fail("你能加的內力最大值為你的max_force的十倍, 你想轉換的點數太高了!!\n");

    write("你嘗試將魔封環裡所積聚的能量轉換成自己的內力!!\n");
   
    me->add("force",point * 5);
    me->add("mo_fon_hoan/point",-point);
    write("你的內力增加了!!\n");
    return 1;
}     
    

    

void heart_beat()
{
        object enemy;
        int enemy_exp,me_exp,add_value;
        if( !userp(me) )
        {
        set_heart_beat(0);
        return;
        }
        if(me->is_fighting()){
          enemy=offensive_target(me);
          if(enemy)
            enemy_exp=enemy->query("combat_exp");
          else
            enemy_exp=0;
          me_exp=me->query("combat_exp");
          if(enemy_exp >= me_exp*0.8 && enemy_exp <= me_exp*3)
            me->add("mo_fon_hoan/point",6+random(5));
          else
            me->add("mo_fon_hoan/point",1+random(5));
            add_value=me->query("max_kee")-me->query("kee");
            me->add("mo_fon_hoan/point",add_value);
        }
        else        
        me->add("mo_fon_hoan/point",1+random(3));

        if(me->is_fighting())
        {
                if(10 > random(100))
                {
                me->add("force",500);
                message_vision("$n發出了一道藍光，$N的內力恢復了!!!\n",me,this_object());
                }
        }
        return ;
}
int query_autoload()
{
        return 1;
}
