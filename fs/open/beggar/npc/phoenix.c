inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
object *enemy;
void create()
{
        set_name("幟虹仙鳳", ({ "phoenix" }) );
        set("race", "野獸");
        set("attitude", "aggressive");
        set("age", 1000);
        set("max_gin", 350000);
        set("max_kee", 350000);
        set("max_sen", 350000);
        set("gin",350000);
        set("sen",350000);
        set("kee",350000);
        set("str", 90);
        set("cor", 90);
        set("spi", 20);
        set("int", 20);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("bellicosity",90000);
        set("max_force",40000);
        set("force",90000);
        set_temp("apply/armor", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 210);
        set_temp("apply/attack", 210);
        set("force_factor",50);
        set("combat_exp", 9900000);
        set_skill("move",100);
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("unarmed",200);
        set_skill("beast-combat",140);
        set_skill("force",400);
        map_skill("unarmed","beast-combat");
        map_skill("parry","beast-combat");
        setup();

}

int accept_kill(object mob)
{
        mob = this_object();
        message_vision(HIG + "\n$N發出一聲天籟般的長鳴，彷彿訴說著千年輪迴的無盡滄桑。\n\n" + NOR,mob);
        message_vision(HIW + "聖靈" + HIB + "轉" + HIG + "生" + HIR + "焰" + HIM + "不斷地燃燒著$N的身軀，宛如浴火重生。\n\n" + NOR,mob);
        mob->set("eff_gin",350000);
        mob->set("gin",350000);
        mob->set("eff_kee",350000);
        mob->set("kee",350000);
        mob->set("eff_sen",350000);
        mob->set("sen",350000);
        mob->delete_busy();
        COMBAT_D->report_status(mob);
        
        return 1;
}


void heart_beat()
{
        string *msg=
          ({
            HIY + "天上立刻降下攝人的" + HIR + "焚星炎。\n" + NOR,
            HIY + "大地震動，裂縫湧出" + HIR + "融岩海。\n" + NOR,
            HIY + "四周空氣立即燃燒為" + HIR + "燎原火。\n" + NOR,
            HIY + "強光直衝九霄，正是" + HIR + "殛天焰。\n" + NOR,
           });
        object mob = this_object();     
        object room= environment(mob);
        int i,j,k,l,m;
        k = sizeof(msg);
        l = random(k);
        enemy = mob->query_enemy(room);
        if(mob->is_fighting() && enemy)
        {
          j = sizeof(enemy);
          for(m=0; m<sizeof(enemy); m++)
          {
          if(enemy[m]->query("id") == "yun")
          j = 0;
          }
          message_vision(HIG + "\n$N發出一聲天籟般的長鳴，彷彿訴說著千年輪迴的無盡滄桑。\n\n" + NOR,mob);
          if(j < 2)
          {
           message_vision(HIW + "聖靈" + HIB + "轉" + HIG + "生" + HIR + "焰" + HIM + "不斷地燃燒著$N的身軀，宛如浴火重生。\n\n" + NOR,mob);
           mob->set("eff_gin",350000);
           mob->set("gin",350000);
           mob->set("eff_kee",350000);
           mob->set("kee",350000);
           mob->set("eff_sen",350000);
           mob->set("sen",350000);
           mob->delete_busy();
           COMBAT_D->report_status(mob);
          }else{
                message_vision("\t"+msg[l]+"\n",mob);
                for(i=0; i<sizeof(enemy); i++)
                {
                 if(random(5) == 3)
                 {
                  message_vision(HIR + "$N全身受到高熱衝擊，頓時灼傷，焦爛不堪。\n" + NOR,enemy[i]);
                  enemy[i]->receive_damage("kee",2000);
                  enemy[i]->receive_wound("kee",2000);
                  COMBAT_D->report_status(enemy[i]);
                 }
                                 if(random(5) == 1)
                                 {
                                  message_vision("\n\n
                          " + HIR + "▁▃" + NOR + "
                    " + HIR + "▂▅▇" + NOR + "" + RED + "" + BBLK + "▄▁▃" + NOR + "
                       " + BLK + "" + BRED + "▆▄ " + RED + "" + BBLK + "◣  " + HIR + "▄▆" + NOR + "" + RED + "" + BBLK + "▆▅▅▄▃▂▁" + NOR + "
                            " + RED + "◥◣ " + HIR + "◥" + BRED + "▉≡ ==—￣ " + BLK + "" + BRED + "▁ " + NOR + "" + RED + "" + BBLK + "▆▄▂" + NOR + "
                  " + HIR + "▁▂" + NOR + "       " + RED + "◥" + BRED + " " + BBLK + "◣" + HBRED + "▉═￣     " + NOR + "" + BLK + "" + BRED + "▁▄" + NOR + "
               " + HIR + "◢" + BRED + "◤◥" + BBLK + "█▆▅▆▇" + BRED + "▆  ＼   " + NOR + "" + RED + "" + BBLK + "▇" + BLK + "" + BRED + "▄" + NOR + "
               " + HIR + "" + BRED + "▍     ◥◥◥ ◥◥▊  " + NOR + "" + RED + "" + BBLK + "◣" + NOR + "
               " + HIR + "" + BRED + "▎   ﹨  ◥◥ ＼＼ ＼    " + NOR + "" + BLK + "" + BRED + "▃" + NOR + "
               " + HIR + "" + BRED + "▏｜  ﹨   ＼ ＼ " + NOR + "" + BLK + "" + BRED + "▄" + NOR + " " + BLK + "" + BRED + "▆▃     " + RED + "" + BBLK + "▃▂▃▁" + NOR,enemy[i]);
                           message_vision("
               " + HIR + "" + BRED + "▏∥         " + NOR + "" + BLK + "" + BRED + "▄" + NOR + "            " + BLK + "" + BRED + "▇" + RED + "" + BBLK + "◥▄  ▂" + BLK + "" + BRED + "▇▅" + RED + "" + BBLK + "▄" + NOR + "
               " + HIR + "" + BRED + "   │     " + NOR + "" + RED + "" + BBLK + "◥" + NOR + "                     " + BLK + "" + BRED + "▅" + RED + "" + BBLK + "▃" + BLK + "" + BRED + "▅" + RED + "" + BBLK + "▃  " + BLK + "" + BRED + "▅" + RED + "" + BBLK + "▃" + NOR + "
               " + HIR + "" + BRED + "   ║   " + NOR + "" + RED + "" + BBLK + "▊▏                         " + BLK + "" + BRED + "▄" + RED + "" + BBLK + "◣ " + BLK + "" + BRED + "▅" + RED + "" + BBLK + "▃ ◥▃" + NOR + "
                " + BRED + "       " + RED + "" + BBLK + "▎                              ◥    ◥▃ ◥▃" + NOR + "
                " + BRED + "     " + RED + "" + BBLK + "▉▏                                ▍     ▌   ◥" + NOR + "
                " + BLK + "" + BRED + "▎  " + RED + "" + BBLK + "▊▎" + NOR + "                                  " + RED + "▍     ◥" + NOR + "
                  " + BRED + "    " + RED + "" + BBLK + "∥                                  ▎       ▍" + NOR + "
                   " + BLK + "" + BRED + " ∣" + NOR + "                                    " + RED + "▍        ▍" + NOR + "
                    " + RED + "◥                                   ▍          ▎" + NOR + "
                                                   " + RED + "▁▂◤             ▏" + NOR + "
                                                                    " + RED + " ▏\n\n" + NOR,enemy[i]);
              message_vision(HIR + "\n仙熾火凰全身夾帶著熾熱的火焰，朝著$N疾速飛來。\n" + NOR,enemy[i]);
              message_vision(HIR + "\n$N全身被火焰包圍著，痛不欲生。\n" + NOR,enemy[i]);
              kee = enemy[i]->query("kee")/20;
                if(environment(mob)==environment(enemy[j])){
              while(j--){
              enemy[j]->receive_wound("kee",kee);
              enemy[j]->receive_damage("kee",kee);
              enemy[j]->apply_condition("burn",6);
              COMBAT_D->report_status(enemy[j]);}
                       }else{
                      message_vision(HIM + "$N以全身勁力抵擋高熱，一時間無法動彈。\n" + NOR,enemy[i]);
                      enemy[i]->start_busy(2);
                      }
                          }
                 if(enemy[i]->query("id") == "yun")  enemy[i]->die();
                }
               }
        }

        set_heart_beat(1);
        :: heart_beat();
}   


void die()
{
object *enemy;
object winner = query_temp("last_damage_from");
object feather,me;
string name = winner->query("name");
me=this_object();  /*指phoenix*/
enemy=me->query_enemy();  /*指攻擊的玩家*/
feather=new("/u/p/pana/obj/feather");
winner->set_temp("ko_phoenix",1);
if (winner->query_kar() > random(33)){
        tell_room(environment(winner),sprintf(HIY + "一片金黃色的羽毛落在%s的身上。\n" + NOR,winner->name()));
    feather->move(winner);}
        tell_object(users(),HIY + "\n\n
                        幟虹仙鳳痛苦的悲鳴著

                ～～～～吼     吼     吼    吼～～～～
                
                                " + HIB + "頓時天崩地裂～～～轟 轟 轟～～～～～" + HIY + "
                
                                   聖獸幟虹仙鳳死於"+winner->name()+"" + HIY + "的手中了。
                                \n" + NOR);
        :: die();
}
