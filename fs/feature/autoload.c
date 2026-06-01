#pragma save_binary
// wade 2002-10-23 加入 quit 可以儲存裝備
// autoload.c
//add autoload function by bss,can save some special value which system want save
//bss 09/24/03
#define NEW_AUTOLOAD "/feature/autoload_new.c"

mapping *autoload;

void clean_up_autoload() { autoload = 0; }

void save_autoload()
{
  object *inv;
  int i, j;
  mixed param;

//this is test by bss
  if(this_object()->query("new_autoload")) NEW_AUTOLOAD->save_autoload(this_object());
//test end by bss
  inv = all_inventory();
  autoload = allocate(sizeof(inv));
  for(i=0, j=0; i<sizeof(inv); i++) {
    if( !(param = inv[i]->query_autoload()) ) continue;
	/*
    autoload[j] = base_name(inv[i]);
    if( stringp(param) ) autoload[j] += ":" + param;
    j++;
	*/
	autoload[i] = ([
	"file_name":base_name(inv[i]),
	"amount":inv[i]->query_amount(),
	"extra_power": inv[i]->query_temp("extra_power")
	]);
  }
  //autoload = autoload[0..j];
  autoload -= ({ 0 });
}

void restore_autoload()
{
  int i;
  object ob;
  mixed file, param, err;
  mixed extra_power;
//tell_object(find_player("whatup"),sprintf("%O\n",autoload));
  if( !pointerp(autoload) ) return;

  for(i=0; i<sizeof(autoload); i++) {
    // printf ("autoload %d = %s\n", i+1, autoload[i]);
	extra_power = 0;

	if(stringp(autoload[i])){

		if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
		  file = autoload[i];
		  param = "1";
		}
	}
	else
	{
		file = autoload[i]["file_name"];
		param = ""+autoload[i]["amount"];
		extra_power = autoload[i]["extra_power"];
	}
	
    err = catch(ob = new(file));
    if( err || !ob ) {
      write("你覺得似乎失落了什麼重要的東西﹐最好通知一下巫師。\n");
      log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
        file, this_object()->query("name"), err));
      continue;
    }
    export_uid(ob);
    ob->autoload(param);
	ob->set_amount(atoi(param));

    ob->move(this_object());
	if(extra_power != 0)
	{
		ob->set_temp("extra_power",copy(extra_power));
	}
  }
//this is test by bss
  if(this_object()->query("new_autoload")) NEW_AUTOLOAD->restore_autoload(this_object());
//test end by bss

  clean_up_autoload();    // To save memory.
}

