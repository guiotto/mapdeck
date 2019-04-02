function add_greatcircle_geo( map_id, greatcircle_data, layer_id, auto_highlight, highlight_colour, legend, bbox, update_view, focus_layer, js_transition, wrap_longitude ) {

  const greatcircleLayer = new GreatCircleLayer({
  	map_id: map_id,
    id: 'greatcircle-'+layer_id,
    data: greatcircle_data,
    pickable: true,
    getWidth: d => d.properties.stroke_width,
    getSourcePosition: d => md_get_origin_coordinates( d ),
    getTargetPosition: d => md_get_destination_coordinates( d ),
    getSourceColor: d => md_hexToRGBA( d.properties.stroke_from ),
    getTargetColor: d => md_hexToRGBA( d.properties.stroke_to ),
    getTilt: d => d.properties.tilt,
    getHeight: d => d.properties.height,
    onClick: info => md_layer_click( map_id, "greatcircle", info ),
    onHover: md_update_tooltip,
    wrapLongitude: wrap_longitude,
    autoHighlight: auto_highlight,
    highlightColor: md_hexToRGBA( highlight_colour ),
    transitions: js_transition || {}
  });

  md_update_layer( map_id, 'greatcircle-'+layer_id, greatcircleLayer );
  if (legend !== false) {
    add_legend( map_id, layer_id, legend );
  }
  md_layer_view( map_id, layer_id, focus_layer, bbox, update_view );
}


function add_greatcircle_polyline( map_id, greatcircle_data, layer_id, auto_highlight, highlight_colour, legend, bbox, update_view, focus_layer, js_transition, wrap_longitude ) {

  const greatcircleLayer = new GreatCircleLayer({
    map_id: map_id,
    id: 'greatcircle-'+layer_id,
    data: greatcircle_data,
    pickable: true,
    getWidth: d => d.stroke_width,
    getSourcePosition: d => md_decode_points( d.origin ),
    getTargetPosition: d => md_decode_points( d.destination ),
    getSourceColor: d => md_hexToRGBA( d.stroke_from ),
    getTargetColor: d => md_hexToRGBA( d.stroke_to ),
    getTilt: d => d.tilt,
    getHeight: d => d.height,
    onClick: info => md_layer_click( map_id, "greatcircle", info ),
    autoHighlight: auto_highlight,
    highlightColor: md_hexToRGBA( highlight_colour ),
    onHover: md_update_tooltip,
    wrapLongitude: wrap_longitude,
    transitions: js_transition || {}
  });

  md_update_layer( map_id, 'greatcircle-'+layer_id, greatcircleLayer );
  if (legend !== false) {
    add_legend( map_id, layer_id, legend );
  }

  md_layer_view( map_id, layer_id, focus_layer, bbox, update_view );
}