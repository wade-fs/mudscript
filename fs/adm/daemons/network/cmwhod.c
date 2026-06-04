// mudlib: Basis
// date:   10/10/92
// author: Truilkan@Basis
// desc:   mudwho client written for MudOS 0.9 (uses DATAGRAM sockets)

// interface:
//
//   call boot() when the mud starts up (in preload() with the code that
//     preloads other socket efun code is a good place to call it from)
//   call halt() when the mud shuts down (e.g. in a shutdown() simul_efun)
//   call add_user(user_object) for each player that logs in (don't forget
//     reconnects by netdeaders).
//   call remove_user(user_object) for each player that logs out.
//     (user::remove() may be a good place to add this call.  Also, you
//     wish to call this when netdeath occurs).

// DAEMON_IP won't need to change unless you want to point to a different
// mudwho dameon.  If you wish to use Portals as your mudwho daemon,
// you'll have to get your mud and mud password added to the Portals
// mudwho daemon database.
//
// Here is information on how to contact existing mudwho daemon admins:
// ---------------------------------------------------------------------
// riemann.math.okstate.edu
// - 139.78.1.15  6889, jds@math.okstate.edu
// amber.ecst.csuchico.edu
// - 132.241.1.43 6889, warlock@ecst.csuchico.edu
// nova.tat.physik.uni-nuebingen.de
// - 134.2.62.161 6889, gamesmgr@taurus.tat.physik.uni-tuebingen.de

#include <net/socket.h> /* includes socket_errors.h indirectly */

// ... production settings ...

#include <net/socket.h> /* includes socket_errors.h indirectly */

#define DAEMON_IP "128.83.194.11" /* actlab */
#define PASSWORD "spin,ach"

#define QUERY_NAME query("cap_name")
#define QUERY_LOGIN_TIME query("last_on")

// these values should be okay as long as you are talking to the Portals daemon
#define REFRESH_INTERVAL 390
#define KEEPALIVE_INTERVAL 120
#define PARTITIONS 10

// you shouldn't need to change anything below this comment

#define TAB "\t"
#define GENERATION "0"
#define	UDP_PORT	6888
#define CLIENT_VERSION "mwp 1.2"

static string mwhod_addr;
static string mudname;
static string keepalive_message;
static string boot_message;
static string comments;
static int socket;

void
log_info(string error)
{
	log_file("cmwhod", ctime(time()) + "\n" + error);
}

static void
send_data(string datagram)
{
	int rc;

	rc = socket_write(socket, datagram, mwhod_addr);
	if (rc != EESUCCESS) {
		log_info("socket_write: " + socket_error(rc) + "\n");
	}
}

static string
header(string op)
{
	return op + TAB + mudname + TAB + PASSWORD;
}
// ...
// ...
void
add_all_users(int which)
{
	object *all;
	int j;

	all = users();
	for (j = 0; j < sizeof(all); j++) {
		add_user(all[j], which);
	}
}

void
refresh(int which)
{
	string err;

	// do the catch() so the call_out won't be lost in case of runtime error.
	err = catch(add_all_users(which));
	if (err) {
		log_info("refresh: " + err + "\n");
	}
	call_out("refresh", REFRESH_INTERVAL / PARTITIONS,
		(which + 1) % PARTITIONS);
}

/*
 * Initialize CMWHOD
 */
void
create()
{
	int error;

	rm(LOG_DIR + "/cmwhod");
	log_info(CLIENT_VERSION + ": cmwhod log for '" + MUD_NAME + "'\n");
	socket = socket_create(DATAGRAM, "read", "close");
	if (socket < 0) {
		log_info("socket_create: " + socket_error(socket) + "\n");
		return;
	}
	error = socket_bind(socket, 0);
	if (error != EESUCCESS) {
		log_info("socket_bind: " + socket_error(error) + "\n");
		return;
    }
	set_comments();
	mwhod_addr = DAEMON_IP + " " + UDP_PORT;
	mudname = MUD_NAME;
	set_keepalive_message();
	set_boot_message();
	call_out("keepalive", KEEPALIVE_INTERVAL);
	call_out("refresh", REFRESH_INTERVAL / PARTITIONS, 0);
}

void
keepalive()
{
	/* shouldn't be able to get a runtime error here */
	send_data(keepalive_message);
	call_out("keepalive", KEEPALIVE_INTERVAL);
}
