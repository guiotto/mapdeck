#include <Rcpp.h>

#include "mapdeck_defaults.hpp"
#include "layers/polygon.hpp"
#include "spatialwidget/spatialwidget.hpp"

Rcpp::List polygon_defaults(int n) {
	return Rcpp::List::create(
		//_["polyline"] = mapdeck::defaults::default_polyline(n),
		_["elevation"] = mapdeck::defaults::default_elevation(n),
		_["fill_colour"] = mapdeck::defaults::default_fill_colour(n),
		_["stroke_colour"] = mapdeck::defaults::default_stroke_colour(n)
	);
}

// [[Rcpp::export]]
Rcpp::List rcpp_polygon_geojson( Rcpp::DataFrame data, Rcpp::List data_types,
                              Rcpp::List params, std::string geometry_columns  ) {

	int data_rows = data.nrows();

	Rcpp::List lst_defaults = polygon_defaults( data_rows );  // initialise with defaults
	std::unordered_map< std::string, std::string > polygon_colours = mapdeck::polygon::polygon_colours;
	Rcpp::StringVector polygon_legend = mapdeck::polygon::polygon_legend;
	Rcpp::StringVector parameter_exclusions = Rcpp::StringVector::create("legend","legend_options","palette","na_colour");

	return spatialwidget::api::create_geojson_downcast(
		data,
		data_types,
		params,
		lst_defaults,
		polygon_colours,
		polygon_legend,
		data_rows,
		parameter_exclusions,
		geometry_columns,
		true  // jsonify legend
	);
}

// // [[Rcpp::export]]
// Rcpp::List rcpp_polygon_quadmesh( Rcpp::DataFrame data,
//                                   Rcpp::List data_types,
//                                   Rcpp::List params,
//                                   Rcpp::List geometry_columns) {
//
// 	int data_rows = data.nrow();
//
// 	Rcpp::List lst_defaults = polygon_defaults( data_rows );  // initialise with defaults
// 	std::unordered_map< std::string, std::string > polygon_colours = mapdeck::polygon::polygon_colours;
// 	Rcpp::StringVector polygon_legend = mapdeck::polygon::polygon_legend;
// 	Rcpp::StringVector parameter_exclusions = Rcpp::StringVector::create("legend","legend_options","palette","na_colour");
//
// 	//Rcpp::List data_types;
//
// 	return spatialwidget::api::create_geojson_quadmesh(
// 		data,
// 		data_types,
// 		params,
// 		lst_defaults,
// 		polygon_colours,
// 		polygon_legend,
// 		geometry_columns,
// 		data_rows,
// 		parameter_exclusions,
// 		true  // jsonify legend
// 		);
// }


// [[Rcpp::export]]
Rcpp::List rcpp_polygon_polyline( Rcpp::DataFrame data, Rcpp::List data_types,
                                 Rcpp::List params, Rcpp::StringVector geometry_columns  ) {

	int data_rows = data.nrows();

	Rcpp::List lst_defaults = polygon_defaults( data_rows );  // initialise with defaults
	std::unordered_map< std::string, std::string > polygon_colours = mapdeck::polygon::polygon_colours;
	Rcpp::StringVector polygon_legend = mapdeck::polygon::polygon_legend;
	Rcpp::StringVector parameter_exclusions = Rcpp::StringVector::create("legend","legend_options","palette","na_colour");

	return spatialwidget::api::create_polyline(
		data,
		data_types,
		params,
		lst_defaults,
		polygon_colours,
		polygon_legend,
		data_rows,
		parameter_exclusions,
		geometry_columns,
		true  // jsonify legend
	);
}

