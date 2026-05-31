inherit F_FUNCTION;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>

int cor=this_player()->query_cor(1);
int k=this_player()->query_spi(1)/10;

string *msg=
({
   HBBLU+HIC"天狗一擊破天靈\n"NOR,
   BCYN+HIW"天狗二吠徹雲霄\n"NOR,
   HBMAG+HIW"天狗三犬狀聲勢\n"NOR,
   HBRED+HIW"天狗四爪毀萬物\n"NOR,
   BYEL+HIW"天狗五巡驅外敵\n"NOR,
   BWHT+HIB"天狗六奔拓領地\n"NOR,
   HBBLU+HIC"天狗七靈喚風雨\n"NOR,
   HBGRN+HIW"天狗八駿齊過海\n"NOR,
   HBRED+HIC"天狗九重吞日月\n"NOR,
});

int perform(object me)
{
        int i,j,funlv,sklv,damage,range,action;
        object *enemy,ob,weapon;
        enemy=me->query_enemy();
        weapon=me->query_temp("weapon");
        funlv=me->query("functions/skydog/level",1);
        sklv=me->query_skill("staff",1);
        range=sizeof(msg);
        action=random(range);
        if (!me->is_fighting())
                return notify_fail("天狗蝕日只能在戰鬥中使用！\n");
        if (me->query("class") != "beggar")
                return notify_fail("你非丐幫之人，無法使用！\n");
        if ((int)me->query_skill("pkdog-staff",1) < 70)
                return notify_fail("你打狗技巧不足以發動天狗蝕日！\n");
        if(!(ob=me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff")
                return notify_fail("你必須裝備一把杖才能施展『天狗蝕日』！\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你都沒力了，還想叫狗咬人？\n");
        if ((int)me->query("force") < 50)
                return notify_fail("你內力不夠，狗兒也沒力了！\n");
      message_vision("\n\n"HIR"$N將"+ weapon->query("name") +"往上一拋，口中唸唸有詞，瞬時地動天搖，無數的"HIW"天狗"HIR"從天而降...."NOR"

        "MAG"～　"HIR"『"HIW" 天 "HIR"』"MAG"　～　"HIR"『 "HIW"狗 "HIR"』　"MAG"～　"HIR"『 "HIW"蝕 "HIR"』　"MAG"～　"HIR"『"HIW" 日"HIR" 』　"MAG"～\n\n"NOR,me);
                        {
       if (funlv > 95 && random(200) < random(me->query_kar(1)+me->query_spi(1)))
        {
        string a1,a2;
          object weaponn;
          message_vision(HIC"$N一時會意打狗精髓，接連暢意地使用所有杖法！\n"NOR,me);
          me->add("force",-150);
          for (j=0 ; j <9 ; j++)
                {
                a1 = msg[j];
                a2 = "\n";
                a2 += "\t"+a1;
                message_vision(a2,me);
                for( i = 0 ; i < sizeof(enemy) ; i++)
                 {
                   if (funlv > random(125))
                   {
                    message_vision(HIY"$n只能眼睜睜看著重棒連擊而來，啊的一聲，口中鮮血直流！\n"NOR,me,enemy[i]);
                    damage = cor*2 + (int)me->query_skill("staff",1) +random(100);
                    enemy[i]->receive_wound("kee",damage);
                    enemy[i]->receive_damage("kee",damage);
                    me->add("force",-200);
                //    enemy[i]->receive_damage("sen",enemy[i]->query("eff_sen",1)/30);
                //    enemy[i]->receive_damage("gin",enemy[i]->query("eff_gin",1)/30);
                    enemy[i]->start_busy(random(k)+1);
                    COMBAT_D->report_status(enemy[i]);
                      }else{
                          damage= cor + (int)me->query_skill("staff",1)/3; 
                          message_vision(YEL"$n雖逃過這一擊，但仍被棍氣給傷！\n"NOR,me,enemy[i]);
                          enemy[i]->receive_wound("kee",damage);
                          me->add("force",-100);
                          COMBAT_D->report_status(enemy[i]);
                         }
                        }//結束 for 2
                }//結束for 1
                me->start_busy(1);
        }//結束if
        else 
      {if (funlv <20)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + random(600);  
        }
        else if (funlv <30 && funlv >=20)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*2 + random(600);
        }
        else if (funlv <40 && funlv >=30)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*3 + random(600);
        }
        else if (funlv <50 && funlv >=40)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*4 + random(600);
        }
        else if (funlv <60 && funlv >=50)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*5 + random(600);
        }
        else if (funlv <70 && funlv >=60)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*6 + random(600); 
        }
        else if (funlv <80 && funlv >=70)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*7 + random(600); 
        }
        else if (funlv <90 && funlv >=80)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*8 + random(600); 
        }
        else if (funlv <101 && funlv >=90)
      {
        message_vision("\t"+msg[action]+"\n",me);
        damage= cor*funlv*sklv/1000 + cor*9 + random(600); 
        }
        me->add("force",-100);
        me->start_busy(1);
        for (i=0;i<sizeof(enemy);i++)
        {
          if(!me || !enemy[i]) continue;
          if(environment(me)!=environment(enemy[i])) continue;
          if(random(100) > 20)
          {
            enemy[i]->receive_wound("kee",damage);
            enemy[i]->start_busy(1);
            message_vision(HIY"$n只能眼睜睜看著重棒連擊而來，啊的一聲，口中鮮血直流！\n"NOR,me,enemy[i]);
            COMBAT_D->report_status(enemy[i]);
          }
          else  
           {message_vision(YEL"$n雖逃過這一擊，但仍被棍氣給傷！\n"NOR,me,enemy[i]);
             enemy[i]->receive_wound("kee",damage/4);
             COMBAT_D->report_status(enemy[i]);
            }
          }
        }
        }//結束message
    if(funlv<100) { function_improved("skydog",150+random(funlv/2)); }
    return 1;
}


