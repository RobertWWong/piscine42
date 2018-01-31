#!/usr/bin/perl
use warnings;
use strict;

#this line creates our perl script, which takes an x, y, and density integer argument
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {		#this piece of code here determins when a wall appears
			print "o";
		}
		else {
			print ".";
		}
	}
print "\n";
}
