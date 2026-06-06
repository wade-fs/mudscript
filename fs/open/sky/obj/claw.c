//調整使用者的判定以減少玩家離線 或者持有者不存在時會出錯 by blazakira 2011/3/29

#include <weapon.h>
#include <ansi.h>
#include <combat.h>
#include <dev_obj.c>
inherit UNARMED;
object wp = this_object();
object me;
void create()
{
  set_name(HIG"爪"NOR,({"attribute-claw"}) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long","存在著未知靈力的神秘武器。(請以check level查詢兵器狀態，change變化兵器型態。)\n");
    set("value", 2000);
    set("sharp",9);
    set("material","blacksteel");
    set("no_give",1);
    set("no_steal",1);
    set("no_drop",1);
    set("no_auc",1);
    set("no_sell",1);
    set("no_put",1);
    set("no_sec",1);
    set("no_save",1);
    set("dev_wp",1);
  }
  init_unarmed(92);
  setup();
}

void init()
{
  me=environment(wp);
  if( !wp || !me ) return;
  if( !wp->query("boss") ) wp->set("boss",me->query("id"));
  if(!wp->query("original_name")) wp->set("original_name",wp->query("name"));
  wp->init0();
  add_action("do_check","check");
  add_action("do_wield","wield");
  add_action("do_unwield","unwield");
  add_action("do_change","change");
}

int do_check(string str)
{
  int level;
  string att;
  if(str == "level")
  {
    wp->init0();
    level = wp->query("dev_level");
    att = me->query("attribute");
    if(att == "fire")  att = "火炎";
    else if(att == "ice")  att = "寒冰";
    else if(att == "dark")  att = "玄冥";
    else if(att == "saint")  att = "仙天";
    tell_object(me,"您的職業屬性為"+att+"系。
您的"+wp->query("name")+"目前為第"+chinese_number(level)+"級兵器。\n");
  }
}

int do_wield(string str)
{
  int uexp;
  object user = this_player();
  if(wp->query("wmsg"))  set("wield_msg",CYN"$N"CYN"拿起"+wp->query("name")+""CYN"。\n"NOR);
  if(str && (str == wp->query("id") || str == "all"))
  { 
    uexp = user->query("combat_exp");
    if( uexp < 7000000 )
    {
      message_vision("$N的江湖歷練並不足以駕馭這樣的靈動神器!!\n"NOR,user);
      set_heart_beat(0);
    }else{
      message_vision(CYN""+wp->query("wmsg")+""CYN"逐漸四散瀰漫整個空間!!\n"NOR,user,wp);
      set_heart_beat(1);
    }
  }
}

int do_unwield(string str)
{
  if(wp->query("uwmsg"))  set("unwield_msg",CYN"四散的"+wp->query("uwmsg")+""CYN"逐漸回歸"+wp->query("name")+""CYN"。\n"NOR);
  if(str == wp->query("id") || str=="all")
  if( query("equipped") )
  {
    message_vision(CYN"$N輕輕卸下$n。\n"NOR,this_player(),wp);
    set_heart_beat(0);
  }
}

void heart_beat()
{
  object *enemy,ewp;
  int level,c,i,j,spi,per,ratio,add,attack;
  string att,con,ski_type;
  if( !wp || !me ) return;
  spi = me->query_spi();
  per = me->query_per();
/*
  if(!wp)
  {
    set_heart_beat(0);
    return;
  }
*/
  att = wp->query("attribute");
  level = wp->query("dev_level");
  if(att == "water")
  { 
    if(me->query("water") < 450)  me->add("water",2);
    if(!me->is_fighting() && me->query_temp("water_add_def")) //流水系非戰鬥時防禦加成消失
    {
      add = me->query_temp("water_add_def");
      me->add_temp("apply/defense",-add);
      me->add_temp("apply/dodge",-add);
      me->delete_temp("water_add_def");
      message_vision(HIB"激鬥過後，水之結界逐漸退卻。\n"NOR,me);
    }
  }
  if(att == "ground" && !me->is_fighting() && me->query_temp("ground_add_def")) //大地系非戰鬥時parry加成消失
  {
    add = me->query_temp("ground_add_def");
    me->add_temp("apply/parry",-5*add);
    me->add_temp("apply/dodge",3*add);
    me->delete_temp("ground_add_def");
    message_vision(YEL"激鬥過後，大地的加持逐漸消散。\n"NOR,me);
  }
  if(!wp->query("equipped"))
  {
    set_heart_beat(0);
    return;
  }
  if(level > 6) //最高級武器平常時有附加作用
  {
    if(att == "fire" && random(level) > 5 && !me->query_condition("kang_pill") && me->query("attribute") != "ice")
    {
      message_vision(HIW"從"+wp->query("name")+""HIW"流出一道幟熱罡\氣，由$N掌心傳至丹田。\n"NOR,me);
      me->apply_condition("kang_pill",level); //非寒冰系使用者持火炎系武器附加kang-power
      me->set_temp("kang-power",1);
    }
    if(att == "wind" && random(level) > 5 && me->query("busy") && me->query("attribute") != "ground" && !me->is_fighting())
    {
      message_vision(HIW"ㄧ陣溫暖清風拂過，$N原本動彈不得的身軀頓時間減輕了不少壓力。\n"NOR,me);
      me->delete_busy(); //非大地系使用者持疾風系武器附加非戰鬥狀態解busy
    }
    if(att == "saint" && random(level) > 5 && !me->query_condition("mon_pill") && me->query("attribute") != "dark")
    {
      message_vision(HIY"陣陣仙氣自"+wp->query("name")+""HIY"中發散出來，流至$N身上。\n"NOR,me);
      me->apply_condition("mon_pill",level); //非玄冥系使用者持仙天系武器有回復能力
    }
  }
  if(!me->is_fighting() || me->query_temp("unconcious")) return;
  enemy = me->query_enemy();
  j = sizeof(enemy);
  if(j<1) return;

  if(att == "fire") //火炎系 主破壞 高level時對寒冰系敵人附加攻擊
  {
    if(level > 0 && random(2+(me->query("fire-spirit"))) > 0 )
    if( random(spi) > 28 || random(per) > 15 || random(10) == 1 )
      message_vision(wp->query("amsg"),me);
    for(i=0;i<j;i++)
    {
      if((enemy[i]) && environment(enemy[i]) == environment(me))
      {
        if(enemy[i]->query("attribute"))
        if(enemy[i]->query("attribute") == "ice" && enemy[i]->query("attribute") == "dark")   ratio = 2; //對暗、冰系加成
        else ratio = 1;
        c = random(5);
        if(enemy[i]->query("attribute") && enemy[i]->query("attribute") == "water") c = 2; //對水系無效
        if(c != 2)
        {
          tell_object (enemy[i],wp->query("wmsg")+""HIY"對你造成極其嚴重的灼傷!!\n"NOR);
          enemy[i]->receive_wound("kee",level*100*ratio); //最低 100 最高1500
          COMBAT_D->report_status(enemy[i]);
        }
        else tell_object (enemy[i],wp->query("wmsg")+YEL"堪堪在你身旁掠過，真是險象環生。\n"NOR);
        if(!me->is_busy() && me->query("fire-spirit") && ratio == 2 && random(level) > 3) //level 4以上有可能對相剋屬性做額外攻擊
        {
          message_vision(HIR"冰火不容，"+wp->query("wmsg")+""HIR"牽動$N的戰意，朝$n展開另一波攻勢。\n"NOR,me,enemy[i]);  
          COMBAT_D->do_attack(me, enemy[i], wp, 1);
        }
      }
    } 
    return;
  }

  if(att == "ice") //寒冰系 主困敵 高level時對火炎系敵人附加攻擊
  {
    if(level > 0)
    if(random(2+me->query("ice-spirit")) > 0 && (random(spi) > 28 || random(per) > 15 || random(10) == 1))
      message_vision(wp->query("amsg"),me);
    for(i=0;i<j;i++)
    {
      if((enemy[i]) && environment(enemy[i]) == environment(me))
      {
        if(enemy[i]->query("attribute") && enemy[i]->query("attribute") == "fire")   ratio = 3; //對火系加成
        else ratio = 2;
        c = random(5);
        if(enemy[i]->query("attribute") && enemy[i]->query("attribute") == "water")  c = 2; //對水系無效
        if(c != 2)
        {
          tell_object (enemy[i],wp->query("wmsg")+""HIC"的冰封頓時讓你身軀僵硬，動彈困難!!\n"NOR);
          enemy[i]->start_busy(1 + random(ratio)); //最低busy1 最高busy3
          if(enemy[i]->query("force_factor") > level && random(ratio) >= 1)
          enemy[i]->add("force_factor",random(ratio));
          COMBAT_D->report_status(enemy[i]);
        }
        else tell_object (enemy[i],wp->query("wmsg")+"GRN""襲來，你只是顫抖了幾下，倒沒發生什麼事。\n"NOR);
        if(!me->is_busy() && me->query("ice-spirit") && ratio == 3 && random(level) > 3)
        {
          message_vision(HIC"冰火不容，"+wp->query("wmsg")+""HIC"牽動$N的戰意，朝$n展開另一波攻勢。\n"NOR,me,enemy[i]);
          COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
        }
      }
    }
    return;
  }

  if(att == "water") //流水系 主防禦，戰鬥中會逐漸增加防禦力，戰鬥結束後立即消退
  {
    if(random(2+me->query("water-spirit")) > 0 && (random(spi) > 28 || random(per) > 16 || random(12) == 1))
    {
      if(me->query("attribute") == "water")    ratio = 1;     //水系持有者效果較好
      else if(me->query("attribute") == "fire")    ratio = 3; //火系持有者效果較差
      else ratio = 2;
      add = level/ratio;
      me->add_temp("apply/defense",add); //最高ㄧ次加7   (水系)
      me->add_temp("apply/dodge",add);   //最高一次加7   (同上)
      me->add_temp("water_add_def",add); //將加過的量記錄起來
      message_vision(wp->query("amsg"),me);
    }
    return;
  }

  if(att == "ground" && !me->query_temp("ground_add_def")) //大地系 主防禦，戰鬥中格檔率爆增、閃避率暴降，戰鬥結束立即消退
  {
    if(random(2+me->query("water-spirit")) > 0 &&(random(spi) > 28 || random(per) > 16 || random(12) == 1))
    {
      if(me->query("attribute") == "ground")    ratio = 3; //地系持有者加成
      if(me->query("attribute") == "wind")    ratio = 1;   //風系持有者效果較差
      else ratio = 2;
      add = ratio*level;
      me->add_temp("apply/parry",5*add);  // en parry 最高加105  (地系)
      me->add_temp("apply/dodge",-3*add); // en dodge 最高減63   (同上)
      me->set_temp("ground_add_def",add); //將加(減)過的量記錄起來
      message_vision(HIW"頓時"+wp->query("wmsg")+""HIW"大盛，$N感覺自己的防禦有如銅牆鐵壁般牢不可破。\n"NOR,me);
    }
    return;
  }

  if(att == "wind") //疾風系 主速攻，以密集但較低的攻擊力出招，對大地屬性無效
  {
    if(!me->query_busy() && me->query("force") > 2000 && me->query("bellicosity") > 1000 && !me->query_temp("unconcious"))
      if(random(2+me->query("wind-spirit")) > 0 &&(random(spi) > 28 || random(per) > 16 || random(12) == 1))
      {
        if(me->query("attribute") == "wind")    ratio = 3;   //風系持有者加成
        if(me->query("attribute") == "ground")    ratio = 1; //地系持有者效果較差
        else ratio = 2;
        add = (1+level)/2;
        add = random(ratio + add); //最大出招數為風系ppl在level7時，六招
        if(add < 1) add = 1;
        ski_type = wp->query("skill_type");
        attack = me->query_skill(ski_type);
        me->add_temp("apply/"+ski_type,-attack/2); //將攻擊skill的en level減半
        if(level < 7) message_vision(HIW"$N的身影倏地消失，化為ㄧ陣"+wp->query("uwmsg")+"飛快攻擊。\n"NOR,me);
        else message_vision(HIW"\n$N高聲大喊："HIC"『"HIG"神 ～ 風 ～ 動 ～"HIC"』\n"HIR"頓時瘋狂殺招無窮無盡，源源不絕而出。\n"NOR,me);
        for(c=0;c<=add;c++)
        {
          if(!enemy[i] || environment(me) != environment(enemy[i]) || enemy[i]->query("attribute") == "ground") continue;
          if(me->query_busy()) break;
          COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
          me->add("force",-200);
        }
        me->add_temp("apply/"+ski_type,attack/2); //將攻擊skill的en level加回來
        message_vision(HIW"\n行招過後，$N冷笑道："HIR"『"HIC"你大概也聽到了吧！暖風拂過的清脆響聲。"HIR"』\n"NOR,me);
      }
      return;
  }

  if(att == "dark") //玄冥系 主狀態 高level時對仙天系敵人附加攻擊
  {
    if(level > 0)
    if(random(2+me->query("dark-spirit")) > 0 &&(random(spi) > 28 || random(per) > 16 || random(12) == 1))
      message_vision(wp->query("amsg"),me);
    for(i=0;i<j;i++)
    {
      if((enemy[i]) && environment(enemy[i]) == environment(me))
      {
        if(enemy[i]->query("attribute") && enemy[i]->query("attribute") == "saint")   ratio = 3;
        else ratio = 1;
        if(random(5) != 2)
        {
          tell_object (enemy[i],wp->query("wmsg")+""HIY"對你身心造成極大破壞，各種隱疾一觸即發。!!\n"NOR);
          for(c=0;c<1+(ratio)/2;c++)
          switch(random(ratio+level))
          {
            case 0:
              con = "no_power_f";
              break;
            case 1:
              con = "no_power_e";
              break;
            case 2:
              con = "no_power";
              break;
            case 3:
              con = "super_snake_poison";
              break;
            case 4:
              con = "fog_poison";
              break;
            case 5:
              con = "flower";
              break;
            case 6:
              con = "ff_poison";
              break;
            case 7:
              con = "power-down";
              break;
            case 8:
              con = "death";
              break;
            case 9:
              con = "enforce_poison";
              break;
            default:
              con = "spring";
              break;
          }
          enemy[i]->apply_condition(con,(1+ratio)/2);
          COMBAT_D->report_status(enemy[i]);
        }
        else tell_object (enemy[i],wp->query("wmsg")+YEL"在你強大的護體罡\氣前化為烏有!!\n"NOR);
        if(!me->is_busy() && me->query("dark-spirit") && ratio == 3 && random(level) > 3)
        {
          message_vision(HIG"自古正邪不兩立，"+wp->query("wmsg")+""HIG"牽動$N的戰意，朝$n展開另一波攻勢。\n"NOR,me,enemy[i]);
          COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
        }
      }
    }
    return;
  }

  if(att == "saint") //仙天系 主回復 高level時對玄冥系敵人附加攻擊
  {
    if(level > 0)
    if(random(2+me->query("light-spirit")) > 0 &&(random(spi) > 28 || random(per) > 15 || random(10) == 1))
      message_vision(wp->query("amsg"),me);
    if(me->query("attribute") == "saint") ratio = 4;     //仙天系持有者效果加倍
    else if(me->query("attribute") == "dark") ratio = 1; //玄冥系持有者效果減半
    else ratio = 2;                                      //其他系持有者效果持平
    me->receive_curing("gin",level*30*ratio); // 29 < 回復量 < 840
    me->receive_heal("gin",level*30*ratio);
    me->receive_curing("kee",level*50*ratio); // 49 < 回復量 < 840
    me->receive_heal("kee",level*50*ratio);
    me->receive_curing("sen",level*30*ratio);
    me->receive_heal("sen",level*30*ratio);
    COMBAT_D->report_status(me);
    for(i=0;i<j;i++)
    {
      if((enemy[i]) && environment(enemy[i]) == environment(me))
      {
        if(enemy[i]->query("attribute") && enemy[i]->query("attribute") == "dark") ratio = 2;
        else continue;
        if(!me->is_busy() && me->query("light-spirit") && ratio == 2 && random(level) > 3)
        {
          message_vision(HIY"自古正邪不兩立，"+wp->query("wmsg")+""HIY"牽動$N的戰意，朝$n展開另一波攻勢。\n"NOR,me,enemy[i]);
          COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 1);
        }
      }
    }
    return;
  }
  return;
}

int query_autoload()
{
  return 1;
}

int do_change(string str)
{
  if( me->query_temp("no_change") == 1 )  return notify_fail("暫時無法做武器變化!!\n");

  switch(str)
  {
    case "unarmed":
      set("skill_type", "unarmed");
      set_name( HIG"爪"NOR,({"attribute-claw"}));
      wp->set("original_name",HIG"爪"NOR);
      write("一道靈光由天而降，一雙利爪出現在眼前。\n");
      break;
    case "sword":
      set("skill_type", "sword");
      set_name( HIG"劍"NOR,({"attribute-sword"}));
      wp->set("original_name",HIG"劍"NOR);
      write("一道靈光由天而降，一柄銳劍出現在眼前。\n");
      break;
    case "archery":
      set("skill_type", "archery");
      set_name( HIG"弓"NOR,({"attribute-bow"}));
      wp->set("original_name",HIG"弓"NOR);
      write("一道靈光由天而降，一把長弓出現在眼前。\n");
      break;    
    case "blade":
      set("skill_type", "blade");
      set_name( HIG"刀"NOR,({"attribute-blade"}));
      wp->set("original_name",HIG"刀"NOR);
      write("一道靈光由天而降，一把巨刀出現在眼前。\n");
      break;
    case "dagger":
      set("skill_type", "dagger");
      set_name( HIG"刃"NOR,({"attribute-dagger"}));
      wp->set("original_name",HIG"刃"NOR);
      write("一道靈光由天而降，一柄利刃出現在眼前。\n");
      break;
    case "throwing":
      set("skill_type", "throwing");
      set_name( HIG"翼"NOR,({"attribute-wing"}));
      wp->set("original_name",HIG"翼"NOR);
      write("一道靈光由天而降，一對飛翼出現在眼前。\n");
      break;      
    case "whip":
      set("skill_type", "whip");
      set_name( HIG"鍊"NOR,({"attribute-chain"}));
      wp->set("original_name",HIG"鍊"NOR);
      write("一道靈光由天而降，一條長鍊出現在眼前。\n");
      break;
    case "needle":
      set("skill_type", "stabber");
      set_name( HIG"針"NOR,({"attribute-needle"}) );
      wp->set("original_name",HIG"針"NOR);
      write("一道靈光由天而降，一柄尖針出現在眼前。\n");
      break;
    case "fan":
      set("skill_type", "stabber");
      set_name( HIG"扇"NOR,({"attribute-fan"}) );
      wp->set("original_name",HIG"扇"NOR);
      write("一道靈光由天而降，一柄羽扇出現在眼前。\n");
      break;
    case "staff":
      set("skill_type", "staff");
      set_name( HIG"鎚"NOR,({"attribute-star"}) );
      wp->set("original_name",HIG"鎚"NOR);
      write("一道靈光由天而降，一柄重鎚出現在眼前。\n");
      break;
    case "lance":
      set("skill_type", "lance");
      set_name( HIG"槍"NOR,({"attribute-lance"}) );
      wp->set("original_name",HIG"槍"NOR);
      write("一道靈光由天而降，一柄長槍出現在眼前。\n");
      break;
    case "axe":
      set("skill_type", "axe");
      set_name( HIG"斧"NOR,({"attribute-axe"}) );
      wp->set("original_name",HIG"斧"NOR);
      write("一道靈光由天而降，一把巨斧出現在眼前。\n");
      break;
    default:
      write("這種兵器型態並不存在於狂想空間，請選擇適當的種類。\n");
  }
  init0();
  return 1;
}
