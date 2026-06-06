// user.c

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_ALIAS;
inherit F_EDIT;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_AUTOLOAD;

static int last_age_set, count=0;

void create()
{
	seteuid(getuid());
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "終端機型態設定為 " + term_type + "。\n", this_object());
}

void reset()
{
//	if( origin()!=ORIGIN_DRIVER ) return;

	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

    if(this_object()->query("bss/cp_user"))
    id=this_object()->query("id");
    else
	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;
	if (getuid() == "guest") return 1;
	// 🚀 關鍵修正：若尚未設定個人身分 (仍為 Root)，則不存檔，避免產生 Root.o
	if (geteuid() == ROOT_UID || !geteuid()) return 1;

	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	set("age", 14+(int)query("age_modify")+((int)query("mud_age")/86400));
	if (query("一週") < 833360000) {
	  set("一週", time());
	  set("一週上線時間", 0);
	}
	if (time()-query("一週") > 604800) {	// 七天, 一週
	  set("一週", time());
	  set("一週上線時間", 0);
	}
	else
	  add("一週上線時間", time()-last_age_set);
  /* if(query("一週上線時間") > 234000) {
	  if ((count = (count+1)%20) == 0)
	    write ("小朋友, 你一週玩太久不好喔, 請自行保重身體.\n");
	  else if (query("一週上線時間") > 252000) {
	    write ("同一週上線太常不好喔, 請自行保重身體.\n");
	    if (!wizardp(this_object()))
	      command("quit");
      }
    }  */ 
	last_age_set = time();
}

void setup()
{
	log_file("init.log", sprintf("DEBUG: user.c::setup() called for %O\n", this_object()));
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
	log_file("init.log", sprintf("DEBUG: user.c::setup() finished for %O\n", this_object()));

	// 🚀 新增：發送網頁 UI 初始資料 (相容 fsmud web client)
	if (interactive(this_object())) {
		mapping data = ([
			"hp": query("kee"),
			"max_hp": query("max_kee"),
			"mp": query("sen"),
			"max_mp": query("max_sen"),
			"money": "請輸入 score 查詢"
		]);
		write(sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data)));
		
		mapping cmds = ([
			"基本": ({ "look", "score", "hp", "inventory", "who", "chat" }),
			"移動": ({ "north", "south", "east", "west", "up", "down" }),
			"其他": ({ "help", "save", "quit" }),
		]);
		write(sprintf("{\"ui\": \"cmd_list\", \"title\": \"常用指令\", \"data\": %s}", json_encode(cmds)));
	}
}

protected void user_dump(int type, int idle_time_out)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "斷線超過 "
				+ NET_DEAD_TIMEOUT/60 + " 分鐘﹐自動退出這個世界。\n");
//斷線必quit by bss
            set_temp("must_be_quit",1);
			command("quit");
			break;
		case DUMP_IDLE:
			tell_object( this_object(), "對不起﹐您已經發呆超過 " 
				+ idle_time_out/60 + " 分鐘了﹐請下次再來。\n");
			tell_room( environment(), "一陣風吹來﹐將發呆中的" + query("name")
				+ "化為一堆飛灰﹐消失了。\n", ({this_object()}));
            set_temp("must_be_quit",1);
			command("quit");
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
protected void net_dead()
{
	object link_ob;
	string	*channels;
	int	i;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) ) {
		link_ob->save();
		destruct(link_ob);
	}

	set_temp("netdead", 1);
	if( userp(this_object()) ) {
	  call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	  tell_room(environment(), query("name") + "斷線了。\n", this_object());
	  message("sys", 
	  	"【系統】"+query("name")+"("+query("id")+")斷線了。\n",
		filter_array(users(), "wizards", this_object())
	  );
	  // CHANNEL_D->do_channel(this_object(), "sys",
	  //	"【系統】"+query("name")+"("+query("id")+")斷線了。\n");
 
	  log_file("quit", 
                sprintf("%s(%s)於 %s 斷線。\n他的上一個命令是 '%s'\n"
			"他的現在的命令是 '%s'\n",
                  query("name"),
                  query("id"),
                  ctime(time()),
                  query_temp("last_input"), query_temp("current_input"))
	  );
	  save();
	}
	else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "重新連線完畢。\n");
}

int wizards(object who)
{
  return wizardp(who);
}
