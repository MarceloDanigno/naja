module top(input in, output out);
wire [5:5] feedtru;

assign feedtru[5] = in;
assign out = feedtru[5];

endmodule //top
