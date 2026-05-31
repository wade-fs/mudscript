//排版 與調整ident_armor()裡對於exp的限制 by blazakira 2011/10/22
//獨立對於query("armor_prop/armor")限制的判定並與armor.h的限制數值相同 與補上職業限制判斷為現有的class by blazakira 2011/10/25

#include <weapon.h>
#include <armor.h>

int help(object);
int ident_weapon(object me,object ob,int lv);
int ident_armor(object me,object ob,int lv,int flag);
int ident_food(object me,object ob,int lv,int flag);
int ident_water(object me,object ob,int lv,int flag);
int ident_lighter(object me,object ob,int lv,int flag);
int ident_item(object me,object ob,int lv,int flag);

int main(object me, mixed arg)
{
  string type="item";
  object ob;
  int lv,cost;
  seteuid(getuid());
  if( !arg ) return help(me);

  if( me->is_fighting() ) return notify_fail("你正在戰鬥中，無法鑑定物品！\n");
  if(objectp(arg)) ob = arg;
  else if( stringp(arg) &&!(ob = present(arg,me))) return notify_fail("你身上沒這個東西！\n");
  else if(!ob) return notify_fail("你身上沒這個東西！\n");
  for (lv=0;(lv*lv*lv*1000) <= me->query("combat_exp");lv++);
  lv=(lv > (me->query_skill("trade")/5))?(me->query_skill("trade")/5):lv;
  cost = (me->query_spi()-30) / 2;
  if (wizardp(me)){lv=20;cost=0;}
  me->add("sen",-cost);
  write("物品："+ob->name()+"    你鑑定它的性質大約為：\n");
  if (ob->limit_ident(me))
    return notify_fail("\n\n唉呀！這物品似乎被某種封印封住了，你怎麼看也看不出它任何性質！\n\n");
  if (ob->query("skill_type"))
  {
    type = "weapon";
    ident_weapon(me,ob,lv);
  }
  if (ob->query("armor_type"))
  {
    if (type=="item") ident_armor(me,ob,lv,1);
    else ident_armor(me,ob,lv,0);
    type = "armor";
  }
  if (ob->query("食物"))
  {
    if (type=="item") ident_food(me,ob,lv,1);
    else ident_food(me,ob,lv,0);
    type = "food";
  }
  if (ob->query("液體"))
  {
    if (type=="item") ident_water(me,ob,lv,1);
    else ident_water(me,ob,lv,0);
    type = "water";
  }
  if (ob->query("light_up"))
  {
    if (type=="item") ident_lighter(me,ob,lv,1);
    else ident_lighter(me,ob,lv,0);
    type = "lighter";
  }
  if (type=="item") ident_item(me,ob,lv,1);
  ob->identify(me,lv);
  return 1;
}

int ident_weapon(object me,object ob,int lv)
{
  int value,err;
  string gen;
  if (lv < 1)
  { 
    write("\n也許\是知識不足吧！你無法看出任何性質！\n");
    return 1;
  }
  switch(ob->query("skill_type"))
  {
    case("axe")     : write("斧類武器");break;
    case("blade")   : write("刀類武器");break;
    case("dagger")  : write("短刃武器");break;
    case("hammer")  : write("槌類武器");break;
    case("stabber") : write("刺擊武器");break;
    case("staff")   : write("杖類武器");break;
    case("stick")   : write("棍類武器");break;
    case("sword")   : write("劍類武器");break;
    case("throwing"): write("丟擲暗器");break;
    case("unarmed") : write("空手武器");break;
    case("whip")    : write("鞭類武器");break;
    case("archery") : write("弓類武器");break;

    default: write("不知是不是你見識太少，你怎麼看也看不出這是啥東西！\n"+
        "請個聰明的巫師來看看也許\是個不錯的主意！\n");
      return 1;break;
  }
  if (lv >= 2)
  {
    err=(ob->query("value") / 15);
    if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
    else value=0;
    value+=ob->query("value");
    if (value<0) value=0-value;
    write ("\t價值："+value);
    value=ob->query_weight()/100;
    write ("\t重量："+(value/10)+"."+(value%10));
  }
  write("\n");
  if (lv >= 3)
  {
    err=(ob->query("weapon_prop/damage") / 15)+ 6;
    if(lv < 11) value=random(6+err*(11-lv)/2)-random(6+err*(11-lv));
    else value=0;
    value+=ob->query("weapon_prop/damage");
    if (value<0) value=0-value;
    write("攻擊傷害力："+value+"\t");
  }
  if (wizardp(me)&&value>120) write("武器強度超過限定！請回報負責巫師檢查。\n ("+(string)base_name(ob)+")\n");
  if (lv >= 4)
  {
    value=ob->query("flag");
    if(!value) write("性質： 無");
    else
    {
      write("性質: ");
      if(value & TWO_HANDED) write("雙手 ");
      if(value & SECONDARY)  write("副武器 ");
      if(value & EDGED)      write("刀刃類 ");
      if(value & POINTED)    write("穿刺類 ");
      if(value & LONG)       write("長兵器 ");
    }
  }
  write("\n");
  if (lv >= 5)
  {
    value=ob->query("need_exp");
    if(!value) write("經驗值限制： 無");
    else
    { 
      write("經驗值限制: "+chinese_number(value)+"點");
    }
  }
  write("\t\t");
  if (lv >= 5)
  {
    gen=ob->query("gender_only");
    if(!gen) write("性別限制： 無");
    else
    {
      if (gen=="女性")
      write("性別限制: 女性");
      else
        write("性別限制: 男性");
    }
  }
  write("\n");
  if (lv>=5)
  switch(ob->query("need_class"))
  {
    case("fighter")  : write("職業限制：武術家");break;
    case("swordsman"): write("職業限制：劍俠");break;
    case("blademan") : write("職業限制：刀客");break;
    case("scholar")  : write("職業限制：書生");break;
    case("taoist")   : write("職業限制：道士");break;
    case("dancer")   : write("職業限制：舞者");break;
    case("prayer")   : write("職業限制：聖火教徒");break;
    case("poisoner") : write("職業限制：魔教徒");break;
    case("bandit")   : write("職業限制：惡賊");break;
    case("marksman") : write("職業限制：射手");break;
    case("officer")  : write("職業限制：官員");break;
    case("doctor")   : write("職業限制：醫者");break;
    case("beggar")   : write("職業限制：乞丐");break;
    case("killer")   : write("職業限制：殺手");break;
    default: write("職業限制：無\n");
      break;
  }
  write("\n");
  if (lv >= 6)
  {
    mapping prop;
    int i;
    string *skill;
    if(ob->query("rigidity"))
    { 
      err=(ob->query("rigidity") / 15);
      if(lv < 13) value=random(6+err*(13-lv)/2)-random(6+err*(13-lv));
      else value=0;
      value+=ob->query("rigidity");
      if (value > ob->query("rigidity")/2) write("武器震傷力："+value+"\n");
    }
    prop=ob->query("weapon_prop");
    skill = keys(prop);
    for(i=0; i<sizeof(prop) && lv > 0; i++)
    {
      if (!(file_size("daemon/skill/"+skill[i]+".c") == -1))
      {
        printf("%-15s 技能效應： %d\n",to_chinese(skill[i]) + "(" + skill[i] + ")",prop[skill[i]]);
        lv--;
      }
    }
  }
  return 1;
}

int ident_armor(object me,object ob,int lv,int flag)
{
  int value,err,armor,i;
  mapping prop;
  string *skill,gen;
  if (lv < 1)
  { 
    write("\n也許\是知識不足吧！你無法看出任何性質！\n");
    return 1;
  }
  switch(ob->query("armor_type"))
  {
    case(TYPE_HEAD)    : write("護具種類：頭盔");break;
    case(TYPE_NECK)    : write("護具種類：護符");break;
    case(TYPE_CLOTH)   : write("護具種類：上衣");break;
    case(TYPE_ARMBANDS): write("護具種類：臂環");break;
    case(TYPE_PANTS)   : write("護具種類：脛甲");break;
    case(TYPE_WAIST)   : write("護具種類：腰帶");break;
    case(TYPE_WRISTS)  : write("護具種類：護腕");break;
    case(TYPE_SHIELD)  : write("護具種類：盾牌");break;
    case(TYPE_FINGER)  : write("護具種類：右手戒指");break;
    case(TYPE_FINGER2) : write("護具種類：左手戒指");break;
    case(TYPE_HANDS)   : write("護具種類：手套");break;
    case(TYPE_BOOTS)   : write("護具種類：鞋子");break;
    case(TYPE_CAPE)    : write("護具種類：披風");break;
    case(TYPE_LEGGINGS): write("護具種類：護膝");break;
    default: write("奇怪！你怎麼看都看不出這東西該穿在哪！\n也許\該請個巫師看看了。\n");
      return 1;break;
  }
  if (lv >= 2 && flag)
  {
    err=(ob->query("value") / 15);
    if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
    else value=0;
    value+=ob->query("value");
    if (value<0) value=0-value;
    write ("\t價值："+value);
    value=ob->query_weight()/100;
    write ("\t重量："+(value/10)+"."+(value%10));
  }
  write("\n");
  if (lv >= 4)
  {
    armor=ob->query("armor_prop/armor");
    switch(ob->query("armor_type"))
    { //armor增加的限制調整為armor.h的數據 用以統一 by blazakira
      case(TYPE_CLOTH)   : armor=armor*12;break;
      case(TYPE_SHIELD)  : armor=armor*15;break;
      case(TYPE_HEAD)    :
      case(TYPE_PANTS)   : armor=armor*20;break;
      case(TYPE_FINGER2) : armor=armor*10;break;
      case(TYPE_FINGER)  :
      case(TYPE_NECK)    :
      case(TYPE_ARMBANDS):
      case(TYPE_WAIST)   :
      case(TYPE_WRISTS)  :
      case(TYPE_HANDS)   :
      case(TYPE_BOOTS)   :
      case(TYPE_LEGGINGS):
      case(TYPE_CAPE)    : armor=armor*30;break;
    }

    err=(armor / 15);
    if(lv < 11) value=random(6+err*(11-lv)/2)-random(6+err*(11-lv));
    else value=0;
    value+=armor;
//    if (value<0) value=0-value;
    switch(ob->query("armor_type"))
    {
      case(TYPE_HEAD)    : write("戴在頭上，可加強頭部"+value+"點防禦力");break;
      case(TYPE_NECK)    : write("戴在脖子，對頸部產生"+value+"點防護力");break;
      case(TYPE_CLOTH)   : write("穿在身上，可保護身體"+value+"點");break;
      case(TYPE_ARMBANDS): write("戴在手臂，可防禦手臂"+value+"點");break;
      case(TYPE_PANTS)   : write("穿在腿上，可產生腿部防禦力"+value+"點");break;
      case(TYPE_WAIST)   : write("繫在腰上，可加強腰部"+value+"點防禦力");break;
      case(TYPE_WRISTS)  : write("裝備在手腕，手腕防護力上昇"+value+"點");break;
      case(TYPE_SHIELD)  : write("拿在手上，盾牌防衛能力上昇"+value+"點");break;
      case(TYPE_FINGER)  : write("戴在手指，防禦力加強"+value+"點");break;
      case(TYPE_FINGER2) : write("戴在手指，防禦力加強"+value+"點");break;
      case(TYPE_HANDS)   : write("穿在手上，手部防護增強"+value+"點");break;
      case(TYPE_BOOTS)   : write("裝備成鞋子，腳部防禦力增加"+value+"點");break;
      case(TYPE_CAPE)    : write("披在背部，加強後心"+value+"點防護力");break;
      case(TYPE_LEGGINGS): write("裝備於膝蓋\，加強腳部防護"+value+"點");break;
    }
  }
  write("\n");
  if (lv >= 5)
  {
//    value=ob->query("need_exp");
//    if(!value) write("經驗值限制： 無");
    if(!ob->query("need_exp")) write("經驗值限制： 無");
    else
    { 
      write("經驗值限制: "+chinese_number(ob->query("need_exp"))+"點");
    }
  }
  write("\t\t");
  if (lv >= 5)
  {
    gen=ob->query("gender_only");
    if(!gen) write("性別限制： 無");
    else
    {
      if (gen=="女性")
        write("性別限制: 女性");
      else
        write("性別限制: 男性");
    }
  }
  write("\n");
  if (lv>=5)
  switch(ob->query("need_class"))
  {
    case("fighter")  : write("職業限制：武術家");break;
    case("swordsman"): write("職業限制：劍俠");break;
    case("blademan") : write("職業限制：刀客");break;
    case("scholar")  : write("職業限制：書生");break;
    case("taoist")   : write("職業限制：道士");break;
    case("dancer")   : write("職業限制：舞者");break;
    case("prayer")   : write("職業限制：聖火教徒");break;
    case("poisoner") : write("職業限制：魔教徒");break;
    case("bandit")   : write("職業限制：惡賊");break;
    case("marksman") : write("職業限制：射手");break;
    case("officer")  : write("職業限制：官員");break;
    case("doctor")   : write("職業限制：醫者");break;
    case("beggar")   : write("職業限制：乞丐");break;
    case("killer")   : write("職業限制：殺手");break;
    default: write("職業限制：無\n");
      break;
  }
  if(lv >= 3 && ob->query("rain_cover")) write ("\n具防雨功\能");
  if(lv >= 6 && ob->query("thunder")) write ("\n具避雷功\能");
  write ("\n");
  if (wizardp(me)&&value>300) write("防具防禦強度超過限定！請回報負責巫師檢查。\n ("+(string)base_name(ob)+")\n");
  if(lv >= 5 && ob->query("armor_prop/armor_vs_force"))
  {
    err=(ob->query("armor_prop/armor_vs_force") / 15);
    if (lv < 10) value=random(6+err*(10-lv)/2)-random(6+err*(10-lv));
    else value=0; //放在這裡 代表有設定內勁就忽略armor_prop/armor的數值? 獨立判定 by blazakira
    value+=ob->query("armor_prop/armor_vs_force");
    if (value<0) value=0-value;
    write("內勁防護效應："+value+"\n");
  }
  if (wizardp(me)&&value>60) write("內勁防護強度超過限定！請回報負責巫師檢查。\n ("+(string)base_name(ob)+")\n");
  lv-=6;
  if (lv < 1) return 1;
  if( ob->query("armor_prop/damage") )
    write("額外傷害增加："+ob->query("armor_prop/damage")+"\n"); //補充之 作為檢測的依據 by blazakira
  prop=ob->query("armor_prop"); //防具上 設定額外增減的技能數值
  skill = keys(prop);
  for(i=0; i<sizeof(prop) && lv > 0; i++)
  {
    if (!(file_size("daemon/skill/"+skill[i]+".c") == -1)) //技能為技能目錄下存在的話
    {
      printf("%-15s 技能效應： %d \n",to_chinese(skill[i]) + "(" + skill[i] + ")",prop[skill[i]]);
      lv--;
    }
  }
  lv = lv/2;
  if(lv < 1) return 1;
  write("\n目前鑲入的寶物：\n"); //鑲印系統
  if(sizeof(ob->query_temp("extra_power/file")))
  {
    i = 0;
    foreach(string id,string filename in ob->query_temp("extra_power/file"))
    {
      i++;
      printf("[%02d] %-15s \n",i,load_object(filename)->short());
    }
    write("\n額外附加技能效應：\n");
    prop=ob->query_temp("extra_power/apply");
    lv--;
    if(lv == 0) return 1;
    skill = keys(prop);
    for(i=0; i<sizeof(prop) && lv > 0; i++)
    {
      if (!(file_size("daemon/skill/"+skill[i]+".c") == -1))
      {
        printf("%-15s 技能效應： %d \n",to_chinese(skill[i]) + "(" + skill[i] + ")",prop[skill[i]]);
        lv--;
      }
    }
  }
  else
  write("無\n");
  return 1;
}

int ident_food(object me,object ob,int lv,int flag)
{
  int value,err;
  if(!lv)
    return notify_fail("啊！這東西可以吃耶！\n");
  if (lv >= 1 && flag)
  {
    err=(ob->query("value") / 15);
    if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
    else value=0;
    value+=ob->query("value");
    if (value<0) value=0-value;
    write ("\t價值："+value);
    value=ob->query_weight()/100;
    write ("\t重量："+(value/10)+"."+(value%10));
  }
  write("\n");
  if((value=ob->query("食物/剩")) < 1) 
    return notify_fail("嗯！看起來可以吃，但是好像己經被吃光了！\n");
  if (lv >= 3) write ("這東西看起來好像很好吃耶！真好，還有"+CHINESE_D->chinese_number(value)+"次份可以吃！\n");
  if (lv >= 4)
  {
    err=(ob->query("食物/供應") / 15);
    if (lv < 7) value=random(6+err*(7-lv)/2)-random(6+err*(7-lv));
    else value=0;
    value+=ob->query("食物/供應");
    if ( value < 0 ) value = 0 - value;
    write("你估計它大約可以提供你一餐\"+value+"％的能量\n");
  }
  return 1;
}

int ident_water(object me,object ob,int lv,int flag)
{
  int value,err;
  if(!lv)
    return notify_fail("啊！是飲料喔！\n");
  if (lv >= 1 && flag)
  {
    err=(ob->query("value") / 15);
    if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
    else value=0;
    value+=ob->query("value");
    if (value<0) value=0-value;
    write ("\t價值："+value);
    value=ob->query_weight()/100;
    write ("\t重量："+(value/10)+"."+(value%10));
  }
  write("\n");
  if((value=ob->query("液體/剩")) < 1) 
    return notify_fail("嗯！看起來是喝的，但是好像己經沒了！\n");
  value = (value+1)/2;
  if (lv >= 3) write ("這裡面裝的是"+(string)ob->query("液體/名稱")+"，大概還有"+value+"升的容量！\n");
  if (lv >= 4)
  {
    err=(ob->query("液體/止渴") / 15);
    if (lv < 7) value=random(6+err*(7-lv)/2)-random(6+err*(7-lv));
    else value=0;
    value+=ob->query("液體/止渴");
    if (value<0) value=0-value;
    write("你估計它約可以提供你一餐\"+value+"﹪的水份\n");
  }
  return 1;
}

int ident_lighter(object me,object ob,int lv,int flag)
{
  int value,err;
  if(!lv) return notify_fail("具照明功\能。\n");
  if (lv >= 1 && flag)
  {
    err=(ob->query("value") / 15);
    if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
    else value=0;
    value+=ob->query("value");
    if (value<0) value=0-value;
    write ("\t價值："+value);
    value=ob->query_weight()/100;
    write ("\t重量："+(value/10)+"."+(value%10));
  }
  write("\n");
  err=ob->query("light_up");
  if (lv >= 3 && err > 0)
  {
    err=err/15;
    if (lv < 8) value=random(6+err*(8-lv)/2)-random(6+err*(8-lv));
    else value=0;
    value+=ob->query("light_up");
    if (value<0) value=0-value;
    write ("它具有照明的功\用，看起來它大概還可以用"+value+"分鐘\n");
  }
  if (lv >= 5 && err < 0)
    if (lv >= 9 || random (9-lv) < 1) 
      write("它發出柔柔的微光，照亮你的四週！\n");
  return 1;
}

int ident_item(object me,object ob,int lv,int flag)
{
  int value,err;
  if (lv < 1)
  {
    write("\n也許\是知識不足吧！你無法看出任何性質！\n");
    return 1;
  }
  err=(ob->query("value") / 15);
  if (lv < 6) value=random(6+err*(6-lv)/2)-random(6+err*(6-lv));
  else value=0;
  value+=ob->query("value");
  if (value<0) value=0-value;
  write ("\t價值："+value);
  value=ob->query_weight()/100;
  write ("\t重量："+(value/10)+"."+(value%10)+"\n");
  return 1;
}

int help(object me)
{
  write (@HELP
指令格式 : ident [物品]
指令說明 :
           這指令可以讓你對物品做鑑定的工作！鑑定的
         工作除了要有豐富的交易經驗之外，還得見多識
         廣。否則就只能算個殺價高手罷了，不能成為一
         個真正的鑑賞家！一般而言鑑定需要花費相當的
         心神，但是確能夠得到比一般看東西更多的資訊，
         另外有些東西是得經過鑑定後才會顯現它的能力
         的！
HELP);
  return 1;
}
