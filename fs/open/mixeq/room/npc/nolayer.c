//可以把寶石跟裝備合成起來的人by bss
#include <ansi.h>
inherit NPC;
string do_ask_stone();
string do_ask_mix();
string do_ask_tool();
void create()
{
    set_name("諾雷爾",({"nolayer"}) );
    set("gender", "男性");
    set("age",45);
    set("long", "迷一般的人\n");
    set("inquiry", ([
          "祝福寶石" : (: do_ask_stone :),
          "靈魂寶石" : (: do_ask_stone :),
          "幸福寶石" : (: do_ask_stone :),
          "合成"     : (: do_ask_mix :),
          "工具"     : (: do_ask_tool :),
    ]) );
    set("no_kill",1);
    set("no_fight",1);
    setup();
}
string do_ask_stone()
{
    command("say 你竟然會知道這種寶石？");
    command("say 你真是找對人了，這個世界只有我知道這個寶石的作用");
    command("say 這是一種可以跟裝備合成的寶石，用來提高裝備的力量");
    return "\n";
}
string do_ask_mix()
{
    object ppl;
    int step;

    if(!ppl=this_player()) return "what did you say?\n";
    step=ppl->query("mixeq/quest_step");
    if(!step){
      command("say 你又問對人了，這個世界上只有我會合成裝備");
       command("say 我是可以幫你合成啦，只不過嘛......我的工具不見了，也許\你可以幫我找一下");
      ppl->set("mixeq/quest_step",1);
    }else if(step>1 && step <10){
      command("say 我的工具你又還沒拿給我，就要我幫你合成，你太誇張了吧？");
    }else if(step==10){
      command("say 合成的方式很簡單，我這邊有一張說明書，你拿去看看就了解了");
    }else{
       command("say 合成？我不太懂耶，你也許\可以去問問別人喔！");
    }
    return "\n";
}
string do_ask_tool()
{
    object ppl;
    int step;

    if(!ppl=this_player()) return "what did you say?\n";
    step=ppl->query("mixeq/quest_step");
    if(step==1){
      command("say 你要幫我找是吧，那真是多謝你啦");
      command("say 不過我要老實講啦，我自己也不知道工具在哪裡");
      command("say 我來到這個世界的時候工具就......唉，反正說了你也不懂");
      command("say 我可以確定的是你可以在這個世界裡面找到我那個工具");
      command("say 那個工具就是一把槌子，淡藍色的喔，是我好不容易才得到的東西");
      command("say 這麼好認的槌子，好找吧！");
      command("say 一切就拜託你啦");
      ppl->set("mixeq/quest_step",2);
    }else if(step>1 && step < 10){
      command("say ㄏㄛ......ㄚ我不數都講夠了嗎？");
      command("say 沒聽清楚的話抱歉啦，我不想再講第二遍");
    }else if(step==10){
      command("bow "+ppl->query("id"));
      command("say 多謝你幫我找回心愛的工具，要我合成裝備是絕對沒有問題的啦");
    }else{
       command("say 工具？我不太懂耶，你也許\可以去問問別人喔！");
    }
    return "\n";
}

int accept_object(object who,object ob)
{
    int old_lv,old_add,success_ratio;
    string ob_id,who_id,stone;
    object me=this_object();
    object eq;

    who_id=who->query("id");
    ob_id=ob->query("id");
    if(ob_id=="nolayer_hammer"){
      if(ob->query("ob_id")!=ob_id){
        message_vision("$N看了看手上的東西，忽然用力往外一扔，$n從此消失在這個世界。\n",me,ob);
        destruct(ob);
        return 1;
      }
      command("say 太好了，你找到了，我又可以開始我的工作了");
      who->set("mixeq/quest_step",10);
      destruct(ob);
      return 1;
    }
    if(ob->query("armor_type")){
      if(me->query_temp(who_id+"/file")){
        command("say 你又給我一件幹嘛，我一次也只能做一件ㄚ");
        message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
        ob->move(who);
        return 1;
      }
      me->set_temp(who_id+"/file",base_name(ob));
      me->set_temp(who_id+"/old_lv",ob->query("ex_def_power"));
      me->set_temp(who_id+"/old_add",ob->query("ex_add_def"));
      me->set_temp(who_id+"/lucky",ob->query("ex_lucky"));
      command("say 嗯，要用這件裝備合成啊，不能反悔了喔，我可是不會還給你的");
      destruct(ob);
      return 1;
    }
    if(ob_id == "bless_stone" || ob_id == "soul_stone" || ob_id== "lucky_stone" || ob_id=="life_stone"){
      if(ob->query("stone_id")!=ob_id){
        message_vision("$N看了看手上的東西，忽然用力往外一扔，$n從此消失在這個世界。\n",me,ob);
        destruct(ob);
        return 1;
      }
      if(!me->query_temp(who_id)){
        command("say 你要送我這個？那真是太謝謝你了");
        destruct(ob);
        return 1;
      }
      if(ob_id=="bless_stone"){
        old_lv=me->query_temp(who_id+"/old_lv");
        if(old_lv > 5){
          command("say 喔，你給我的裝備等級已經高到用祝福寶石也沒有辦法升級囉，真的要升級的話，就給我靈魂寶石吧");
          command("say 你這件裝備看起來有點壞了，不過我已經幫你修好囉");
          message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
          ob->move(who);
          eq=new(me->query_temp(who_id+"/file"));
          old_lv=me->query_temp(who_id+"/old_lv");
          old_add=me->query_temp(who_id+"/old_add");
          eq->set("ex_def_power",old_lv);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }

        me->set_temp(who_id+"/stone",ob_id);
        command("say 嗯，你要用這顆寶石合成啊，不能反悔了喔，我可是不會還給你的");
        destruct(ob);
        return 1;
      }
      if(ob_id=="soul_stone"){
        old_lv=me->query_temp(who_id+"/old_lv");
        if(old_lv < 6){
          command("say 喔，你給我的裝備等級還不到要使用靈魂寶石啦，真的要升級的話，就給我祝福寶石吧");
          command("say 你這件裝備看起來有點壞了，不過我已經幫你修好囉");
          message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
          ob->move(who);
          eq=new(me->query_temp(who_id+"/file"));
          old_lv=me->query_temp(who_id+"/old_lv");
          old_add=me->query_temp(who_id+"/old_add");
          eq->set("ex_def_power",old_lv);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }
        if(old_lv > 9){
          command("say 嗯，+9等級以上裝備的合成法我有點忘了，等我想起來我再幫你合成吧");
          command("say 你這件裝備看起來有點壞了，不過我已經幫你修好囉");
          message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
          ob->move(who);
          eq=new(me->query_temp(who_id+"/file"));
          old_lv=me->query_temp(who_id+"/old_lv");
          old_add=me->query_temp(who_id+"/old_add");
          eq->set("ex_def_power",old_lv);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }
        me->set_temp(who_id+"/stone",ob_id);
        command("say 嗯，你要用這顆寶石合成啊，不能反悔了喔，我可是不會還給你的");
        destruct(ob);
        return 1;
      }

      if(ob_id=="lucky_stone"){
        if(ob->query("ex_lucky") || me->query_temp(who_id+"/lucky")){
          command("say 嗯，這件裝備之前已經合成過幸運寶石，一件裝備也只能合成一顆，很抱歉");
          command("say 你這件裝備看起來有點壞了，不過我已經幫你修好囉");
          message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
          ob->move(who);
          eq=new(me->query_temp(who_id+"/file"));
          old_lv=me->query_temp(who_id+"/old_lv");
          old_add=me->query_temp(who_id+"/old_add");
          eq->set("ex_def_power",old_lv);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }
        me->set_temp(who_id+"/stone",ob_id);
        command("say 嗯，你要用這顆寶石合成啊，不能反悔了喔，我可是不會還給你的");
        destruct(ob);
        return 1;
      }
      if(ob_id=="life_stone"){
        old_add=me->query_temp(who_id+"/old_add");
        if(old_add >=4){
          command("say 嗯，這件裝備已經沒有辦法再合成生命寶石了，一件裝備最多只能合成四顆，很抱歉");
          command("say 你這件裝備看起來有點壞了，不過我已經幫你修好囉");
          message_vision("$N給了$n一"+ob->query("unit")+ob->short()+"\n",me,who);
          ob->move(who);
          eq=new(me->query_temp(who_id+"/file"));
          old_lv=me->query_temp(who_id+"/old_lv");
          old_add=me->query_temp(who_id+"/old_add");
          eq->set("ex_def_power",old_lv);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }
        me->set_temp(who_id+"/stone",ob_id);
        command("say 嗯，你要用這顆寶石合成啊，不能反悔了喔，我可是不會還給你的");
        destruct(ob);
        return 1;
      }
    }
    if(ob->query("money_id")){
      if(ob->query("money_id")!="diamond"){
        command("say 你要送我這個？那真是太謝謝你了");
        destruct(ob);
        return 1;
      }
      if(!me->query_temp(who_id+"/stone")){
        command("say 你要送我這個？那真是太謝謝你了");
        destruct(ob);
        return 1;

      }
      command("say 嗯，該給的東西都已經給我囉，等我一下，我馬上把合成好的裝備拿給你");
      destruct(ob);
      eq=new(me->query_temp(who_id+"/file"));
      stone=me->query_temp(who_id+"/stone");
      if(stone=="bless_stone"){
        old_lv=me->query_temp(who_id+"/old_lv");
        old_add=me->query_temp(who_id+"/old_add");
        eq->set("ex_def_power",old_lv+1);
        eq->set("ex_add_def",old_add);
        eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
        command("say 耶，合成完畢，夠快吧");
        message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
        eq->move(who);
        me->delete_temp(who_id);
        return 1;
      }else if(stone=="soul_stone"){
        success_ratio=500;
        old_lv=me->query_temp(who_id+"/old_lv");
        old_add=me->query_temp(who_id+"/old_add");
        if(me->query_temp(who_id+"/lucky")) success_ratio=750;
        if(success_ratio > random(1000)){
          eq->set("ex_def_power",old_lv+1);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          command("say 耶，合成完畢，夠快吧");
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          return 1;
        }else{
          eq->set("ex_def_power",old_lv-1);
          eq->set("ex_add_def",old_add);
          eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
          command("say 啊，糟糕，合成失敗了");
          command("sigh");
          command("say 這也是沒辦法的事情，等級高的裝備合成本來就有風險");
          message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
          eq->move(who);
          me->delete_temp(who_id);
          command("say 抱歉啦");
          return 1;
        }
      }else if(stone=="life_stone"){
        old_lv=me->query_temp(who_id+"/old_lv");
        old_add=me->query_temp(who_id+"/old_add");
        eq->set("ex_def_power",old_lv);
        eq->set("ex_add_def",old_add+1);
        eq->set("ex_lucky",me->query_temp(who_id+"/lucky"));
        command("say 耶，合成完畢，夠快吧");
        message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
        eq->move(who);
        me->delete_temp(who_id);
        return 1;
      }else if(stone=="lucky_stone"){
        old_lv=me->query_temp(who_id+"/old_lv");
        old_add=me->query_temp(who_id+"/old_add");
        eq->set("ex_def_power",old_lv);
        eq->set("ex_add_def",old_add);
        eq->set("ex_lucky",1);
        command("say 耶，合成完畢，夠快吧");
        message_vision("$N給了$n一"+eq->query("unit")+eq->short()+"\n",me,who);
        eq->move(who);
        me->delete_temp(who_id);
        return 1;
      }else{
        command("say 合成的過程裡面出了一點問題，不過沒關係，我已經用千里傳音跟大神們講了");
        return 1;
      }
      return 1;
    }
    command("say 你要送我這個？那真是太謝謝你了");
    destruct(ob);
    return 1;
}

