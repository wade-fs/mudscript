inherit NPC;
#include <ansi.h>
string adv_title();
void create()
{
  set_name("傅劍寒的雕像",({"cgy statue","cgy"}));
  set("long","狂想之神。狂想的玩家為了能瞻仰他，紀念他的德行，所以特別建立了此一雕像。\n你可以試著(pray id)也許\有奇妙的效果喔!!\nexp滿一千萬者可以問他關於稱號的事喔");
  set("title",HIR + "惡魔城主" + NOR);
  set("nickname",HIW + "神" + HIG + "劍" + HIC + "飛" + HIY + "龍" + NOR);
  set("unit","尊");
  set("age",291);
  set("value",100);
  set("no_get",1);
  set("no_kill",1);
  set("no_fight",1);
  set("no_sac",1);
  set("no_auc",1);
  set("env/can_tell_wiz","YES");
  set("no_reset",1);
  set_weight(500000);
  setup();
  set("inquiry", ([
    "稱號"  : (:adv_title:),
  ]));
}

init()
{
  add_action("do_pray","pray");
}

int do_pray(string arg)
{
  object me=this_player();

  if( !me->query_temp("cgy_pray_"+arg) )
  {
    call_out("greeting",2,me,arg);
    message_vision(HIW + "一陣光芒籠罩$N" + HIW + "的全身，光芒過後，已將$N" + HIW + "的祈禱傳送到大神的耳邊。\n" + NOR,me);
    me->set_temp("cgy_pray_"+arg,1);
  }else{
    if( me->query_temp("cgy_pray_"+arg) < 2 )
    {
      message_vision(HIW + "已經傳達您的心意了，請耐心等候處理!!\n" + NOR,me);
      me->add_temp("cgy_pray_"+arg,1);
    }else{
      message_vision(HIR + "\n吼!!都說已經正在處理了還來煩，該賞你一記鐵鎚!!\n\n" + NOR,me);
      command("hammer "+me->query("id") );
    }
  }

  return 1;
}

void greeting(object ob,string arg)
{
  object me;
  me=this_player();
  command("tell "+arg+" "+me->query("name")+"("+me->query("id")+")傳送一份祝福的祈禱給您!!\n ");
}

string adv_title()
{
  object me=this_player();
  string classes;
  string t;
  mapping title = ([]);
  
  title["fighter"] =  ({
    HIB + "ζ" + HIC + "武道" + HIY + "˙" + HIR + "奇俠" + HIB + "ζ" + NOR,
    HIY + "ζ" + HIG + "傲世天下" + HIY + "ζ" + HIM + "紫燄" + HIY + "．" + HIC + "武神" + NOR,
    HIG + "拳掌" + HIY + "雙霸" + HIW + "～" + HIC + "笑蒼天" + NOR,
    HIY + "傲世三俠" + HIB + "《" + HIG + "恨 無 敵" + HIB + "》" + NOR,
    HIY + "傲世三俠" + HIB + "《" + HIM + "龍 無 情" + HIB + "》" + NOR,
    HIY + "傲世三俠" + HIB + "《" + HIC + "星 無 蹤" + HIB + "》" + NOR,    
    HIG + "δ青龍δ" + HIY + "當" + HIB + "代" + HIM + "武" + HIW + "神" + NOR,
    HIW + "δ白虎δ" + HIC + "無" + HIG + "雙" + HIR + "武" + HIY + "聖" + NOR,
    HIC + "δ玄武δ" + HIG + "究" + HIB + "極" + HIM + "武" + HIR + "痴" + NOR,
    HIR + "δ朱雀δ" + HIY + "絕" + HIG + "世" + HIC + "武" + HIM + "尊" + NOR,
    HIY + "δ麒麟δ" + HIG + "九" + HIR + "五" + HIM + "武" + HIC + "帝" + NOR,
    HIB + "ζ" + HIR + "身" + HIY + "負" + HIG + "˙武" + HIW + "學˙" + HBRED + "半" + HBGRN + "邊" + HBBLU + "天"NOR+HIB"ζ" + NOR,
  });
  title["prayer"]  = ({
    HIR + "ξ" + HIM + "末日" + HIW + "聖" + HIY + "光" + HIG + "使者" + HIR + "ξ" + NOR,
    HIY + "ζ" + HIM + "滅" + HIB + "世" + HIC + "天" + HIR + "火" + HIW + "武神" + HIY + "ζ" + NOR,
    HIB + "∮" + HIW + "帝魂" + HIB + "∮" + HIM + "聖" + HIR + "火" + HIC + "天" + HIY + "皇" + NOR,
  });
  title["blademan"]  = ({
    HIM + "《" + HIC + "一代香蕉神" + HIM + "》" + HIY + "軟遍千里" + NOR,
    HIW + "◣" + HIC + "一刀傾城" + HIW + "◥" + HIY + "霸" + HIR + "烈" + CYN + "刀" + HIB + "聖" + NOR,
    HIW + "◤" + HIR + "邪魔轉生" + HIW + "◢" + HIG + "妖" + HIM + "-" + HIB + "刀" + HIM + "-" + HIY + "皇" + NOR,
    HIM + "《" + HIC + "一代刀神" + HIM + "》" + HIY + "怒殺千里" + NOR,
    HIB + "ξ" + HIM + "魔光初現" + HIB + "ξ" + HIR + "赤燄" + HIW + "˙" + HIC + "刀尊" + NOR,
    HIR + "刀魂" + HIG + "∮" + HIY + "怒" + HIB + "˙" + HIM + "斬" + HIB + "˙" + HIC + "殺" + NOR,
    HIC + "怒" + HIR + "燄" + HIB + "《" + HIM + "絕" + HIG + "代" + HIY + "刀" + HIW + "狂" + HIB + "》" + NOR,
  });
  title["killer"]  = ({
    HIB + "黑牙聯" + HIR + "首" + HIY + "席" + HIG + "殺" + HIC + "手" + NOR,
    HIW + "ψ" + HIM + "霸魂" + HIW + "、" + HIC + "闇影" + HIW + "ψ" + HIR + "極" + HIG + "道" + HIY + "殺" + HIB + "神" + NOR ,
    HIG + "★" + HIB + "射日必殺組" + HIG + "☆" + HIW + "～" + HIM + "◤" + HIR + "嗜血" + HIC + "狂" + HIG + "魔" + HIM + "◢" + NOR,
    HIG + "★" + HIB + "射日必殺組" + HIG + "☆" + HIW + "～" + HIM + "◤" + HIR + "鬼" + HIG + "之" + HIC + "武者" + HIM + "◢" + NOR,
    HIR + "賞" + HIY + "金" + HIG + "獵" + HIC + "人" + NOR,
    HIG + "★" + HIB + "射日必殺組" + HIG + "☆" + HIW + "～" + HIM + "◤" + HIC + "絕" + HIG + "殺" + HIR + "浪女" + HIM + "◢" + NOR,
  });
  title["marksman"]  = ({
    HIR + "￡" + HIY + "絕世" + HIM + "‧" + HIC + "箭魂" + HIR + "￡" + NOR,        
    HIB + "ζ" + HIR + "箭之痕" + HIY + "‧" + HIC + "冰沁" + HIM + "箭癡" + HIB + "ζ" + NOR,    
    HIC + "◤" + HIR + "箭傲天下" + HIW + "‧" + HIM + "狂箭皇" + HIC + "◢" + NOR,
  });
  title["swordsman"]  = ({
    HIB + "Υ" + HIM + "神劍修羅" + HIB + "Υ" + NOR,
    HIR + "Ξ" + HIY + "靈" + HIB + "幻" + HIM + "天" + HIB + "劍" + HIR + "Ξ" + NOR,
    HIR + "δ"HIW+BRED"血靈" + NOR + ""HIR + "δ"BLK+HBBLU"闇月"HIC+HBBLU"劍魔" + NOR,
    HIM + "《" + HIC + "絕世劍俠" + HIM + "》" + HIY + "芎天蒼宇" + NOR,
    HIM + "∮情∮" + HIC + "仗" + HIG + "劍" + HIR + "江" + HIY + "湖" + NOR,
    HIR + "∮笑∮" + HIG + "逍" + HIY + "遙" + HIW + "神" + HIC + "劍" + NOR,
    HIC + "∮義∮" + HIB + "渡" + HIW + "生" + HIR + "斬" + HIY + "罪" + NOR,
  });
  title["dancer"]  = ({
    HIC + "ζ" + HIY + "一笑傾城" + HIC + "ζ" + HIM + "絕代" + HIW + "．" + HIR + "佳人" + NOR,
    HIB + "ζ" + HIW + "真" + HIY + "‧" + HIM + "女神轉生" + HIB + "ζ" + HIG + "夢幻" + HIY + "‧" + HIC + "天女" + NOR,
    HIR + "ψ" + HIG + "碧" + HIC + "奇" + HIB + "魂" + HIR + "ψ" + HIW + "祈禱" + HIY + "之" + HIM + "舞" + NOR,
    HIC + "幸" + HIY + "運" + HIM + "女" + HIG + "神" + NOR,
    HIG + "舞楓塵" + CYN + "ζ" + HIB + "夜" + HIY + "夢" + HIW + "霜" + HIR + "星" + CYN + "ζ" + NOR,
  });
  title["scholar"]  = ({
    HIM + "《" + HIW + "羽扇" + HIY + "揚" + HIM + "》" + HIB + "強擄" + HIC + "盡滅" + NOR,
    HIW + "ζ" + HIR + "逍" + HIG + "遙" + HIY + "書" + HIB + "聖" + HIW + "ζ" + NOR,
    YEL + "ψ" + HIG + "言" + HIM + "采" + HIB + "辭" + HIR + "華" + YEL + "ψ" + HIC + "文" + CYN + "‧" + HIW + "曲" + CYN + "‧" + HIY + "星" + NOR,
  });
  title["bandit"]  =({
    HIR + "ψ通緝犯ψ" + HIY + "為" + HIB + "惡" + HIC + "最" + HIM + "美" + NOR,
    HIR + "紅" + HIW + "月" + HIB + "《" + HIG + "地" + HIY + "獄" + HIC + "使" + HIM + "者" + HIB + "》" + NOR,
    HIY + "煞" + HIC + "星" + HIB + "《" + HIR + "災" + HIG + "難" + HIM + "終" + HIW + "結" + HIB + "》" + NOR
  });
  title["doctor"]  =({
    HIB + "∮醫神∮" + HIC + "救" + HIG + "人" + HIR + "活" + HIY + "菩" + HIM + "薩" + NOR,
    HIM + "∮醫怪∮" + HIG + "救" + HIB + "一" + HIC + "人" + HIM + "殺" + HIY + "一" + HIR + "人" + NOR,
    HIC + "∮醫仙∮" + HIR + "救" + HIM + "世" + HIY + "閻" + HIC + "王" + HIG + "敵" + NOR,
    HIY + "∮醫聖∮" + HIR + "死" + HIB + "神" + HIG + "作" + HIC + "對" + HIM + "者" + NOR,
    HIR + "∮醫魔∮" + HIG + "無" + HIY + "常" + HIR + "吾" + HIM + "來" + HIC + "判" + NOR,
    HIG + "∮醫鬼∮" + HIY + "請" + HIB + "鬼" + HIR + "拿" + HIG + "藥" + HIM + "單" + NOR
  });

  if(me->query("combat_exp") < 10000000 )
  {
    if(!me->query_temp("not_enough_exp"))
    {
      me->set_temp("not_enough_exp",1);
      return "你的經驗值不夠, 多加磨練後再來找我吧...";
    }else{
      me->add_temp("not_enough_exp",1);
      if(me->query_temp("not_enough_exp") == 2){
        message_vision(CYN + "......經驗值不夠，練強點再來找我吧!!\n" + NOR,me);
        return "去去去";}
      if(me->query_temp("not_enough_exp") == 3){
        message_vision(CYN + "不是告訴過你經驗值不夠了嗎!?去練強點再來啦\n" + NOR,me);
        return "走開啦";}
      if(me->query_temp("not_enough_exp") == 4){
        message_vision(CYN + "就跟你說你經驗值不夠了，啊你是聽不懂喔!?\n" + NOR,me);
        return "你煩不煩啊你...";}
      if(me->query_temp("not_enough_exp") == 5){
        message_vision(CYN + "你還來!?我扁你喔\n" + NOR,me);
        return "還不滾!?";}
      if(me->query_temp("not_enough_exp") == 6)  
      {
        message("system",HIY + "傅劍寒" + HIW + "大聲說道:" + HIM + "不要臉的"HIY+this_player()->name()+HIM"沒事妄想更動頭銜，以後就叫他" + HIG + "沽名釣譽" + HIR + "大白痴" + HIM + "吧\n" + NOR,users());
        me->set("title",HIG + "沽名釣譽" + HIR + "大白痴" + NOR);
        return "哈哈哈!!";
      }
      if(me->query_temp("not_enough_exp") > 6) return "哈哈哈，活該";
    }
  }

  if(!me->query_temp("get-new-title"))
  {
    classes = me->query("class");
    if(undefinedp(title[classes]))
    {
      return "目前沒有你使用的稱號";
    }
    if(me->query("id") == "lts") t = title["blademan"][0];
    if(classes == "blademan")
    {
      int i = random(sizeof(title[classes]));
      if(me->query("family/family_name") == "金刀門" &&  i == 2 )
      {
        t = title[classes][1];
        write("call me 1");
      }
      else if(i==2)
      {
        t = title[classes][2];
        write("call me 2");
      }
      else
        t = title[classes][random(sizeof(title[classes])-3)+3];
    }
    else
      t = title[classes][random(sizeof(title[classes]))];
    me->set("title",t) ;
    message("system",HIY + "傅劍寒" + HIW + "大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"+t+NOR"稱號\n" + NOR,users());
    me->set_temp("get-new-title",1);
    return "恭喜妳獲得新的稱號";
  }
  else
  return "你已經有了";
}
