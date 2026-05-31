//補上receive_damage攻擊方的參數 by blazakira 2011/7/25

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int report=0;
int vet(object me);

int main(object me, string arg)
{
  object ob, coco;
  int sk, sk2, mk, tk, mg, tg, ms, ts, amount, i;
  string str, name, id;
  seteuid(getuid());
  id = me->query("id");
  sk = (int)me->query_skill("cure",1);
  sk2 = (int)me->query_skill("godcure",1);

  if(!me) return 1;
  if(!arg) return notify_fail("指令格式：cmd vet <id>\n");
  if(environment(me)->query("no_kill") == 1)
    return notify_fail("此地不適合醫生看診唷！\n");
  if(arg == id) return notify_fail("你想要自己幫自己看診？\n");
  if(me->query("family/family_name") != "銀針門" && !wizardp(me))
    return notify_fail("你不是個醫生，怎麼能幫人看診？\n");
  if(sk < 120) return notify_fail("你的醫術不夠，尚無資格幫人看診！\n");
  if(sk2 < 100) return notify_fail("你的華佗醫術不夠，尚無資格幫人看診！\n");
  if(!me->query("doctor/vet")) return notify_fail("你還沒有經過華佗的認證唷！n");
  if(me->query("gin") < 50) return notify_fail("你的精力不足，沒有辦法幫人看診！\n");
  if(me->query("sen") < 50) return notify_fail("你的神瞑不足，沒有辦法幫人看診！\n");
  if(me->is_fighting() || me->is_busy()) return notify_fail("你還是先把手邊的事忙完吧！\n");
  arg = lower_case(arg);
  ob = present(arg, environment(me));
  if(!objectp(ob)) return notify_fail("你想要看診哪位病人啊？\n");
  if(!ob->is_character()) return notify_fail("你只能幫人看診好不好！\n");
  if(ob->is_corpse()) return notify_fail("現在才要幫他看診療...太遲了些吧？\n");
  if(ob->query("no_kill")) return notify_fail("他看起來似乎不需要接受看診的樣子！\n");
  if(ob->query("no_askgod")) return notify_fail("他看起來似乎不需要接受看診的樣子！\n");
  if(ob->query_temp("netdead")) return notify_fail("他離開了這個世界，因此無法幫他看診！\n");
  if(ob->query_temp("for_vet") == 1) return notify_fail("你想二次看診？難道你要推翻自己的看診結果？\n");

  mk = (int)ob->query("max_kee");
  tk = (int)ob->query("max_kee");
  mg = (int)ob->query("max_gin");
  tg = (int)ob->query("gin");
  ms = (int)ob->query("max_sen");
  ts = (int)ob->query("sen");
  name = ob->query("name");
  // 修正 bug ，應該要不是使用者，且經驗值大於一點才有機會把人搞暈 by whatup
  if(!userp(ob) && (me->query("combat_exp") > 5000000 && me->query("combat_exp") > ob->query("combat_exp")/2))
   i=random(12);
  else
   i=random(11);
  switch(i)
  {
    case 0:
      report = 1;
      str = YEL"嗯..."+name+"看來只是一點小小的傷風感冒，喝點水休息一會就好了！\n"NOR;
      ob->receive_damage("kee",(random(50)+50),me);
      break;
    case 1:
      str = HIY"喔～"+name+"的腸胃相當不好唷！要注意少吃點刺激性的食物哪！\n"NOR;
      ob->set("food",random(ob->query("food")));
      ob->set("water",random(ob->query("water")));
      break;
    case 2:
      str = HIC"唷喝！"+name+"的脈像四平八穩，毫不紊亂，身強體健，沒有瑕疵，不錯吶！\n"NOR;
      break;
    case 3:
      str = WHT"哎呀！"+name+"面無血色，手腳冰冷，看來是陰陽不合，氣血失調唷！\n"NOR;
      ob->receive_damage("kee",random(sk),me);
      ob->apply_condition("ff_poison",(int)sk/20);
      break;
    case 4:
      str = HIM"嘿嘿！"+name+"臉泛潮紅，目露色光，看來是慾火高漲，寂寞難耐哪！\n"NOR;
      ob->apply_condition("spring",(int)sk/20);
      break;
    case 5:
      str = CYN"嗯..."+name+"額冒虛汗，全身無力，看來是肝弱膽衰，虛火上升！\n"NOR;
      ob->receive_damage("gin",(random(50)+50),me);
      ob->receive_damage("kee",(random(50)+50),me);
      ob->receive_damage("sen",(random(50)+50),me);
    case 6:
      str = MAG"不得了！"+name+"臉色泛青，嘴唇發紫，一看就知道是被蛇咬傷，中了蛇毒唷！\n"NOR;
      ob->receive_damage("kee",random(sk),me);
      if(ob->query_temp("poison/snake_poison"))
        ob->set_temp("poison/snake_poison",ob->query_temp("poison/snake_poison") - ({ me }) - ({ 0 }) + ({ me }) );
      else
        ob->set_temp("poison/snake_poison",({ me }));
      ob->apply_condition("snake_poison",(int)sk/20);
      break;
    case 7:
      str = HIR"ㄟ..."+name+"額頭發燙，頭暈目眩，想來必是日照過多，一不小心就中暑了！\n"NOR;
      ob->receive_damage("kee",random(sk),me);
      ob->apply_condition("burn",(int)sk/20);
      break;
    case 8:
      str = HIB"咿！"+name+"全身發冷，不停顫抖，推斷應是體濕吹風，受了風寒，無啥大礙也！\n"NOR;
      ob->receive_damage("kee",random(sk),me);
      ob->apply_condition("cold",(int)sk/20);
      break;
    case 9:
      str = GRN"去..."+name+"看來不過就只是酒喝太多，有點酒後微醺，神智不清而已！\n"NOR;
      ob->apply_condition("drunk",(int)sk/20);
      break;
    case 10:
      str = HIG"嘖嘖！"+name+"的身體居然健壯如牛，毫無病痛，真是恭喜恭喜！\n"NOR;
      break;
    case 11:
      str = RED"天呀！"+name+"的心肝脾肺腎全爛光了，看來還是回家準備料理後事吧！\n\n"HIB"沒想到"+name+"聞言，居然「咚」的一聲，暈死過去了！\n"NOR;
      ob->unconcious();
      ob->set("gin",mg);
      ob->set("kee",mk);
      ob->set("sen",ms);
      break;
  }
  message_vision(HIW"$N抓著$n的手，聚精會神的為$n把把脈，開始看診了起來！\n\n"NOR,me, ob);
  message_vision(HIW"過了良久......\n\n$N終於開口說道："+str+"\n",me, ob);
  ob->set_temp("for_vet",1);
  amount = random(sk/3)+30;
  coco = new("/obj/money/silver");
  coco->add_amount(amount);
  coco->move(me);
  message_vision(HIW"$N幫$n看完診，酌收費用"+CHINESE_D->chinese_number(amount)+"文錢！\n"NOR,me, ob);
  me->receive_damage("gin",50,me);
  me->receive_damage("sen",50,me);
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式：cmd vet <id> || 限醫生使用
指令說明：
　　　　醫生應本著仁民愛物的精神，多使用此指令來替人
　　　　進行診療，正是所謂「及早發現及早治療」咩！
HELP);
  return 1;
}
