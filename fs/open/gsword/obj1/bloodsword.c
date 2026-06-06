#include <ansi.h>
#include <weapon.h>
inherit SWORD;
object user;
int sp,max;
void create()
{
     set_name( HIR + "血咒" + NOR,({"blood_sword","sword"}) );
     set_weight(7500);
     if( clonep() )
               set_default_object(__FILE__);
     else {
            set("long","血魔的專用配劍，在戰鬥中可利用其血氣壓制對手.\n"
                      +"釋放血氣: sword_blood,檢查威力:sword_check\n"
                      +"會於戰鬥中自動集氣,集氣越久,威力越強.");
            set("unit", "件");
            set("value",20000);
            set("material","steal");
            set("wield_msg", HIR + "$N從將$n"+HIR + "由畫滿符咒的劍鞘中抽出.\n");
            set("unwield_msg", "$N把$n插回劍鞘裡.\n");
           }
        init_sword(99);
        setup();
}

void init()
{
     add_action("do_wield","wield");
     add_action("do_check","sword_check");
     add_action("do_fire","sword_blood");
}

int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     {
        user = this_player();     // 取得使用者
        sp = 0;
        max = user->query_skill("blood_sword",1);
        set_heart_beat(1);
     }
}
int do_check()
{

 if( query("equipped") )
   write(HIR + "血咒儲存的血氣有 "+sp+" .\n" + NOR);


 return 1;
}
void heart_beat()
{
  if( user->is_fighting() && query("equipped") && sp < max )
  {
   sp++;
  }
     return;
}

int do_fire()
{
  object *enemy;
  int i,pp;

  if( max < 80)
  {
    write("你的劍術太低,無法控制血咒.\n");
    return 1;
  }

  if( user->is_fighting() && query("equipped") )
  {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    if( environment(user) == environment(enemy[i]) )
    {
           if( random(250)+max > enemy[i]->query_skill("dodge") )
      {
        if( sp < 2)
        {
          message_vision("一小道血氣由血咒串出，但由於血氣不足，未到"
                            +"$n身邊時已經消失!!!\n",user,enemy[i]);
          sp=0;
          return 1;
        }else if( sp < 10 )
        {
          message_vision(HIR+"一道血氣由血咒射出,射向$n!!!\n"
                         +NOR,user,enemy[i]);
          pp = sp;
        }else if( sp < 20 )
        {
          message_vision(HIR+"$N手中血咒天一劃,數道血氣由血咒直奔上天，並朝向"
                         +"$n射去!!!\n"+NOR,user,enemy[i]);
          pp=sp*2;
//          enemy[i]->apply_condition("burn",(int)sp*1.5);
        }else if( sp < 30)
        {
          message_vision(HIR+"$N手中長劍一揮,只見天上地上,到處血紅一片,"
                      +"$n陷入了血海中中!!!\n"+NOR,user,enemy[i]);
          pp=sp*3;
          enemy[i]->apply_condition("hellfire",1);
        }else if( sp < 40)
        {
          message_vision(HIR+"$N祭起血咒,只見四週景物開始淡去,無數血氣從朦朧"
                            +"中突然透出,一招血霧刃直接襲擊$n!!\n"
                            +NOR,user,enemy[i]);
          pp=sp*4;
          enemy[i]->apply_condition("hellfire",2);
        }else{
          message_vision(HIR+"$N陷入瘋狂，將手中血劍刺進另一隻手中，只見血咒"
                            +"在吸收$N的鮮血後，散發出耀眼光芒，並釋放出無數"
                            +"血氣包圍$n!!!\n" + NOR,user,enemy[i]);
          user->receive_damage("kee",300);
          pp=sp*7;
          enemy[i]->start_busy(1);
          enemy[i]->apply_condition("hellfire",3);
        }
        sp=0;
        enemy[i]->receive_wound("kee",pp,user);
        COMBAT_D->report_status(enemy[i], 0);
      }else
      {
        message_vision(HIR+"$N嘗試使用血咒..但血咒裡都不理他..\n"+NOR,user);
        sp=sp*0.7;
      }
     }
   }
  return 1;
}

