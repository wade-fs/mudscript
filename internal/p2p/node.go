package p2p

import (
	"encoding/json"
	"log"
	"net/url"
	"sync"

	"github.com/gorilla/websocket"
	pion "github.com/pion/webrtc/v4"
	"mudscript/driver"
	"mudscript/internal/signaling"
	"mudscript/internal/webrtc"
)

type Node struct {
	ID        string
	Driver    *driver.Driver
	Signaler  *websocket.Conn
	Peers     map[string]*Peer
	mu        sync.RWMutex
	
	HubURL    string
}

type Peer struct {
	ID          string
	PC          *pion.PeerConnection
	DataChannel *pion.DataChannel
}

func NewNode(d *driver.Driver, hubURL string) *Node {
	return &Node{
		Driver:   d,
		Peers:    make(map[string]*Peer),
		HubURL:   hubURL,
	}
}

func (n *Node) Start() error {
	u, err := url.Parse(n.HubURL)
	if err != nil {
		return err
	}

	log.Printf("📡 Connecting to signaling hub: %s", u.String())
	c, _, err := websocket.DefaultDialer.Dial(u.String(), nil)
	if err != nil {
		return err
	}
	n.Signaler = c

	go n.readLoop()
	return nil
}

func (n *Node) readLoop() {
	defer n.Signaler.Close()

	for {
		var msg signaling.Message
		err := n.Signaler.ReadJSON(&msg)
		if err != nil {
			log.Println("❌ Signaling read error:", err)
			return
		}

		switch msg.Type {
		case "welcome":
			n.ID = msg.To
			log.Printf("🆔 Node registered with ID: %s", n.ID)
		case "peer-joined":
			// New peer joined the hub, let's initiate connection
			if msg.From != n.ID {
				n.createOffer(msg.From)
			}
		case "offer":
			n.handleOffer(msg)
		case "answer":
			n.handleAnswer(msg)
		case "candidate":
			n.handleCandidate(msg)
		case "chat":
			// Local bridge for interstellar chat
			n.broadcastToMUD(msg.Payload, msg.Username)
		}
	}
}

func (n *Node) createOffer(targetID string) {
	pc, err := pion.NewPeerConnection(webrtc.Config())
	if err != nil {
		log.Println("PC Error:", err)
		return
	}

	dc, err := pc.CreateDataChannel("mud-data", nil)
	if err != nil {
		log.Println("DC Error:", err)
		return
	}

	n.setupDataChannel(targetID, dc)

	pc.OnICECandidate(func(c *pion.ICECandidate) {
		if c == nil { return }
		n.Signaler.WriteJSON(signaling.Message{
			Type: "candidate",
			To:   targetID,
			From: n.ID,
			Candidate: c.ToJSON().Candidate,
		})
	})

	offer, err := pc.CreateOffer(nil)
	if err != nil { return }
	pc.SetLocalDescription(offer)

	n.Signaler.WriteJSON(signaling.Message{
		Type: "offer",
		To:   targetID,
		From: n.ID,
		SDP:  offer.SDP,
	})

	n.mu.Lock()
	n.Peers[targetID] = &Peer{ID: targetID, PC: pc}
	n.mu.Unlock()
}

func (n *Node) handleOffer(msg signaling.Message) {
	pc, err := pion.NewPeerConnection(webrtc.Config())
	if err != nil { return }

	pc.OnDataChannel(func(dc *pion.DataChannel) {
		n.setupDataChannel(msg.From, dc)
	})

	pc.OnICECandidate(func(c *pion.ICECandidate) {
		if c == nil { return }
		n.Signaler.WriteJSON(signaling.Message{
			Type: "candidate",
			To:   msg.From,
			From: n.ID,
			Candidate: c.ToJSON().Candidate,
		})
	})

	pc.SetRemoteDescription(pion.SessionDescription{Type: pion.SDPTypeOffer, SDP: msg.SDP})
	answer, _ := pc.CreateAnswer(nil)
	pc.SetLocalDescription(answer)

	n.Signaler.WriteJSON(signaling.Message{
		Type: "answer",
		To:   msg.From,
		From: n.ID,
		SDP:  answer.SDP,
	})

	n.mu.Lock()
	n.Peers[msg.From] = &Peer{ID: msg.From, PC: pc}
	n.mu.Unlock()
}

func (n *Node) handleAnswer(msg signaling.Message) {
	n.mu.RLock()
	peer, ok := n.Peers[msg.From]
	n.mu.RUnlock()
	if ok {
		peer.PC.SetRemoteDescription(pion.SessionDescription{Type: pion.SDPTypeAnswer, SDP: msg.SDP})
	}
}

func (n *Node) handleCandidate(msg signaling.Message) {
	n.mu.RLock()
	peer, ok := n.Peers[msg.From]
	n.mu.RUnlock()
	if ok {
		peer.PC.AddICECandidate(pion.ICECandidateInit{Candidate: msg.Candidate})
	}
}

func (n *Node) setupDataChannel(peerID string, dc *pion.DataChannel) {
	dc.OnOpen(func() {
		log.Printf("✅ P2P Data Channel opened with peer %s", peerID)
		n.mu.Lock()
		if p, ok := n.Peers[peerID]; ok {
			p.DataChannel = dc
		}
		n.mu.Unlock()
	})

	dc.OnMessage(func(msg pion.DataChannelMessage) {
		// Handle P2P message
		var p2pMsg map[string]string
		json.Unmarshal(msg.Data, &p2pMsg)
		
		if p2pMsg["type"] == "chat" {
			n.broadcastToMUD(p2pMsg["content"], p2pMsg["sender"])
		}
	})
}

func (n *Node) broadcastToMUD(content, sender string) {
	// 透過信令收到的 chat 已經在 hub.go 處理了，這裡主要處理來自 DataChannel 的直接訊息
	if n.Driver.OnP2PMessage != nil {
		n.Driver.OnP2PMessage(sender, content)
	}
}

func (n *Node) SendChat(sender, content string) {
	// 🚀 關鍵修正：透過信令伺服器廣播，確保穩定性與全域覆蓋
	n.Signaler.WriteJSON(signaling.Message{
		Type:     "chat",
		Username: sender,
		Payload:  content,
	})

	// 額外發送到 P2P DataChannel (如果已建立)
	msg := map[string]string{
		"type":    "chat",
		"sender":  sender,
		"content": content,
	}
	data, _ := json.Marshal(msg)

	n.mu.RLock()
	defer n.mu.RUnlock()
	for _, peer := range n.Peers {
		if peer.DataChannel != nil {
			peer.DataChannel.Send(data)
		}
	}
}
