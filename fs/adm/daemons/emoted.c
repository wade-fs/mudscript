// /adm/daemons/emoted.c
// 本檔案改自 es2 mudlib
// 歡迎流傳本檔案, 請保留本檔頭
// wade 1998/7/10

#pragma save_binary

#include <ansi.h>

inherit F_SAVE;

mapping emote;

//  emote mapping 包含 emote 定義的資料庫。
//  每個 emote 可能用到一些變數如下:
//
//  myself  - 送 emote 的玩家
//  target  - emote 的對象
//  others  - 除了下命令的玩家與 emote 的對象以外的其他人
//
//  emote 是使用 'pattern' 來取得相對應的 emote 命令
//  舉例來說, 打 "smile" 會使本 daemon 搜尋 emote mapping 裡的 "smile"
//  而打 "smile someone" 會使本 daemon 搜尋 emote mapping 裡的 "smile $"
//  其中 $ 意味著一個 argument.
//
//  在實際的 emote 訊息裡, 底下的變數會用來替代, 得出真正的訊息
//
//  $N    - emoter 的名字
//  $n    - emote 對象的名字
//  $P    - emoter 的稱謂
//  $p    - emote 對象的稱謂
//
//  Original by Annihilator@ESII (11/09/94)
//  fixed by wade (10/29/1995)
//  增加人物以外的參數的使用

void create()
{
  seteuid(getuid());
  if( !restore() && !mapp(emote) )
    emote = ([]);
}

string query_save_file() { return DATA_DIR + "emoted"; }

// command_hook() of F_COMMAND call this as an alternate command processor.
int do_emote(object me, string verb, string arg, object *who,string channel)
{
  string str, my_gender, target_gender, msg_postfix, others, *e;
 // object target, *targets;  targets 沒用到。
  object target;
  int   remote=0;

  if( !environment(me) ) return 0;

  if ( !mapp(emote) || undefinedp(emote[verb]) ) return 0;

  // Determine the pattern to be searched and the target.
  others = "";
  if ( stringp(arg) && arg != "" ) {
    if (sscanf (arg, "%s %s", arg, others) != 2) others = "";
    if (pointerp(who))
      target = find_living(arg);
    else
      target = present(arg, environment(me));
    if (!target && wizardp(me)) {
        remote = 1;
        target = find_player(arg);
    }
    if (!target || (target->query("env/隱身") && wiz_level(me) < wiz_level(target)) || (target && !target->id(arg))) {
      others = arg+" "+others;
      msg_postfix = "";
    }
    else {
      target_gender = target->query("gender");
      if( target==me ) {
        msg_postfix = "_self";
        target = 0;
      } else msg_postfix = "_target";
    }
  } else msg_postfix = "";

  my_gender = me->query("gender");

  // 送給自己看
  if( stringp(str = emote[verb]["myself" + msg_postfix]) ) {
    str = replace_string(str, "$N", me->name());
    str = replace_string(str, "$P", gender_self(my_gender));
    str = replace_string(str, "$$", others);
    if( objectp(target) ) {
      str = replace_string(str, "$n", target->name());
      str = replace_string(str, "$p", gender_pronoun(target_gender));
    }
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who))
      message("channel_emote",
        channel+str+NOR, me);
    else
      message("emote", HIY+str+NOR, me);
  }
  // 送給對象看
  if( objectp(target) && stringp(str = emote[verb]["target"]) ) {
    str = replace_string(str, "$N", me->name()+"("+me->query("id")+")");
    str = replace_string(str, "$P", gender_pronoun(my_gender));
    str = replace_string(str, "$n", target->name());
    str = replace_string(str, "$p", gender_self(target_gender));
    str = replace_string(str, "$$", others);
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who)) {
        message("channel_emote",
          channel+str+NOR, target );
    }
    else
      message("emote", HIY+str+NOR, target);
  }
  // 送給其他人看
  if( stringp(str = emote[verb]["others"+msg_postfix]) ) {
    str = replace_string(str, "$N", me->name()+"("+me->query("id")+")");
    str = replace_string(str, "$P", gender_pronoun(my_gender));
    str = replace_string(str, "$$", others);
    if( objectp(target) ) {
      str = replace_string(str, "$n", target->name());
      str = replace_string(str, "$p", gender_pronoun(target_gender));
    }
    if (remote) str = "*"+str;
    str=trans_color(str);
    if (pointerp(who)) {
        message("channel_emote", channel+str+NOR, who, ({me, target}));
    }
    else
      message("emote", HIY+str+NOR, environment(me), ({me, target}));
  }

// by ACKY
    if(target)
	if( arg && !userp(target) && userp(me) && verb != "nod" && random(100) < 50 ) {
		e = EMOTE_D->query_all_emote();
		EMOTE_D->do_emote( target, e[random(sizeof(e))], me->query("id") );
	}

  return 1;
}

int save_emotes()
{
  save();
  return 1;
}

int set_emote(string pattern, mapping def)
{
  emote[pattern] = def;
  save();
  return 1;
}

int delete_emote(string pattern)
{
  map_delete(emote, pattern);
  save();
  return 1;
}

mapping query_emote(string pattern)
{
  if( !undefinedp(emote[pattern]) ) return emote[pattern];
  else return ([]);
}

string *query_all_emote()
{
  return keys(emote);
}

mapping query_all_emotes()
{
  return emote;
}
