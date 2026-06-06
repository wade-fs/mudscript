#include <armor.h>
#include <command.h>
#include <ansi.h>
#include <combat.h>
#include <skill.h>
inherit EQUIP;
inherit SSERVER;
object user;
int kar,cor;
void create()
{
        seteuid(getuid());
        set_name(HIC + "影神戒" + NOR ,({"shadow ring", "ring"}));
        set_weight(2500);
        set("no_auc",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_steal",1);
        set("no_save",1);
        if( clonep() )
               set_default_object(__FILE__);
        else {
            set("long","精靈界的寶物，可以召喚出影子俠客組陣殺敵.\n");
            set("unit", "件");
            set("value",50000);
            set("material","gold");
            set("no_sell", 1);         //不然就得多攔 action sell
            set("armor_type","finger");
            set("armor_prop/armor",7);
           }
        setup();
}
void init()
{
     add_action("do_drop","drop");
     add_action("do_auc","auc");
     add_action("do_wear","wear");
     add_action("do_give","give");
     add_action("do_remove","remove");
     add_action("do_move","gomove");
     add_action("do_hand","hand");
     add_action("do_recover","recover");
     add_action("do_sp1","go_array");
     add_action("do_sp2","return");
}
int do_wear(string str)
{
     ::wear();
     if( query("equipped") )
     {
        user = this_player();     // 取得使用者
        kar = user->query_kar();
        cor = user->query_cor();
        cor = cor *2;
        set_heart_beat(1);
     }
}
int do_drop(string str)
{
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        set_heart_beat(0);
     }
}
 int do_give(string str)
{
  if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        set_heart_beat(0);
     }
}
int do_remove(string str)
{
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        set_heart_beat(0);
     }
}
int do_auc(string str)
{
  if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        set_heart_beat(0);
     }
}
int do_move()
{
        object me=this_player();
                me->move("/open/gblade/room/g1-10");
        return 1;
}
int do_hand(string arg)
{
     object me;
     object target;
     int j;

     if(!arg) me=this_player();
     else{
       me=present(arg,environment(this_player()));
       if(!me) return 0;
       else if(!living(me)) return 0;
     }
     if(!me->is_fighting())  return 0;
     target=offensive_target(me);
     for(j=0;j<=7+random(3);j++)
       COMBAT_D->do_attack(me,target,me->query_temp("weapon"),2);
     return 1;
}
int do_recover()
{
     object me=this_player();

     me->set("eff_kee",me->query("max_kee"));
     me->set("eff_gin",me->query("max_gin"));
     me->set("eff_sen",me->query("max_sen"));
     me->set("sen",me->query("max_sen"));
     me->set("kee",me->query("max_kee"));
     me->set("gin",me->query("max_gin"));
     me->clear_condition();
     me->clear_condition("mogi");
     return 1;
}
int do_sp1(string arg)
{
    int num,i;
    object man,me;
    string error,sub,master;

    me=this_player();
    if(me->query("family/family_name")!="仙劍派")
       return notify_fail("目前只給仙劍派使用組陣功能!!\n");
    if(!arg) return notify_fail("指令格式:go_array 人數\n");
    if(!sscanf(arg,"%d",num)) return notify_fail("指令格式:go_array 人數\n");
    if(num!=2 && num!=3 && num!=4 && num!=8)
      return notify_fail("目前只有2,3,4,8這幾種劍陣!!!\n");
    if(me->query_temp("have_array"))
      return notify_fail("你已經有召喚出同伴了!!!\n");
    me->set_temp("have_array",1);
    for(i=1;i<num;i++){
      man=new("/u/b/bss/arraier.c");
      man->set("name",man->query("name")+CHINESE_D->chinese_number(i)+"號");
      man->set("combat_exp",me->query("combat_exp"));
      message_vision(HIM + "一道紫光由$N" + HIM + "射出，$n" + HIM + "出現在眾人的眼前!!\n" + NOR,this_object(),man);
      man->move(environment(me));
      sub=man->query("id");
      master=me->query("id");
//      if(i<2)
        "/cmds/std/team.c"->main(me,"with "+sub);
//      else
//        "/cmds/std/team.c"->main(me,"with "+sub+sprintf(" %d",i-1));
      "/cmds/std/team.c"->main(man,"with "+master);
      man->set_temp("call_by_"+master,1);
      man->set_temp("roared",1);
    }
    write("ok.\n");
    return 1;
}
int do_sp2()
{
    object *inv,me;
    int i;

    me=this_player();
    if(!me->query_temp("have_array"))
      return notify_fail("你並沒有組陣!!!\n");
    me->delete_temp("have_array");
    "/cmds/std/team.c"->main(me,"dismiss");
    inv=all_inventory(environment(me));
    for(i=0;i<sizeof(inv);i++){
      if(!inv[i]) continue;
      if(!inv[i]->query_temp("call_by_"+me->query("id")))
        continue;
      message_vision(HIM + "一道紫光由$N" + HIM + "射出，$n" + HIM + "消失在眾人眼前!!\n" + NOR,this_object(),inv[i]);
      destruct(inv[i]);
    }
    write("ok.\n");
    return 1;
}

void heart_beat()
{
        object *target;
        int i,j,k,l;
  if( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
  if( user->is_fighting() && query("equipped") )
  {
    i=user->query("max_kee",1);
    j=user->query("max_force",1);
    k=user->query("max_gin",1);
    l=user->query("max_sen",1);
    j=j*2;
    user->set("kee",i+100);
    user->set("eff_kee",i);
    user->set("gin",k);
    user->set("eff_gin",k);
    user->set("sen",l);
    user->set("eff_sen",l);
    if(user->query("env/補氣"))
      user->set("force",j);
    user->clear_condition();
    user->clear_condition("mogi");
    target = user->query_enemy();
    if(user->query("env/連擊")){
      for(i=0;i<sizeof(target);i++){
        if(!target[i]) continue;
        target[i]->start_busy(3);
      }
    }
  }
  return;
}


int query_autoload()
{
    return 1;
}
