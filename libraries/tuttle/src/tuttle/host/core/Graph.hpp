#ifndef _TUTTLE_HOST_CORE_GRAPH_HPP_
#define _TUTTLE_HOST_CORE_GRAPH_HPP_

#include "Core.hpp"
#include "Exception.hpp"
#include <tuttle/host/graph/InternalGraph.hpp>
#include <tuttle/host/graph/Vertex.hpp>
#include <tuttle/host/graph/Edge.hpp>
#include <tuttle/host/ofx/attribute/OfxhAttribute.hpp>

#include <boost/ptr_container/ptr_map.hpp>

#include <stdexcept>
#include <string>
#include <map>
#include <list>

namespace tuttle {
namespace host {
namespace core {

class Graph
{
public:
	typedef core::ImageEffectNode Node; /// @todo tuttle ProcessNode...
	typedef core::ProcessAttribute Attribute;
	typedef graph::InternalGraph<graph::Vertex, graph::Edge> InternalGraph;
	typedef graph::InternalGraph<graph::Vertex, graph::Edge>::VertexDescriptor Descriptor;
	typedef boost::ptr_map<std::string, Node> NodeMap;
	typedef std::map<std::string, int> InstanceCountMap;

public:
	Graph();
	Graph( const Graph& other );
	~Graph();

	Node& createNode( const std::string& id );
	void  deleteNode( const Node& node ) throw( exception::LogicError );

	void connect( const Node& out, const Node& in ) throw( exception::LogicError );
	void connect( const Node& out, const Attribute& inAttr ) throw( exception::LogicError );
	void unconnectNode( const Node& node ) throw( exception::LogicError );

	void compute( const std::list<std::string>& nodes, const int tBegin, const int tEnd );
	void compute( const std::list<std::string>& nodes, const int time ) { compute( nodes, time, time ); }

	void compute( const std::string& node, const int tBegin, const int tEnd )
	{
		std::list<std::string> outputs;
		outputs.push_back( node );
		compute( outputs, tBegin, tEnd );
	}
	void compute( const std::string& node, const int time )
	{
		compute( node, time, time );
	}

	const InternalGraph&    getGraph() const         { return _graph; }
	const NodeMap&          getNodes() const         { return _nodes; }
	NodeMap&                getNodes()               { return _nodes; }
	const InstanceCountMap& getInstanceCount() const { return _instanceCount; }

public:
	const Node& getNode( const std::string& id ) const { return _nodes.at( id ); }
	void        dumpToStdOut();

private:
	InternalGraph _graph;
	NodeMap _nodes;
	std::map<std::string, Descriptor> _nodesDescriptor;
	InstanceCountMap _instanceCount; ///< used to assign a unique name to each node

private:
	void addToGraph( Node& node );
	void removeFromGraph( Node& node ) throw( exception::LogicError );
};

}
}
}

#endif

